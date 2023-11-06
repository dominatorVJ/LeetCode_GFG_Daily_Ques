class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size());
        long long sum=0;
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]*1LL);
            long long curr=maxi+nums[i];
            sum+=curr;
            ans[i]=sum;
        }
        return ans;
    }
};