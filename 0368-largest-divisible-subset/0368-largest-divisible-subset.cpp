class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size()+1, 1);
        int mx = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    if(mx<dp[i])
                        mx = dp[i];
                }
            }
        }
        int prv = -1;
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--){
            if(dp[i]==mx && (prv%nums[i]==0 || prv==-1)){
                ans.push_back(nums[i]);
                mx -= 1;
                prv = nums[i];
            }
        }
        return ans;
    }
};