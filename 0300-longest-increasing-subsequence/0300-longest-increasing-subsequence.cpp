class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n);
        dp[0]=1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]>=nums[i]){
                    continue;
                }
                int posans = dp[j]+1;
                if(posans>dp[i]){
                     dp[i] = posans; 
                }
            }
        }
        for(auto i:dp){
            ans = max(ans,i);
        }
        return ans;
    }
};