class Solution {
    int MOD = 1e9 + 7;
public:
    int calc(int n , int k , int target,vector<vector<int>>&dp){
        if(target==0) return n==0;
        if(target<0) return 0;
        if(n<0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans= (ans + calc(n-1,k,target-i,dp))%MOD;
        }
        return dp[n][target]=(ans);
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(31,vector<int>(1001,-1));
        return calc(n,k,target,dp);
    }
};