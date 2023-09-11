class Solution
{
    public:
        int longestCommonSubsequence(string t1, string t2)
        {
            int n = t1.size();
            int m = t2.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
            return recurseMemo(t1, t2, n, m, dp);
        }
    int recurseMemo(string &x, string &y, int n, int m, vector<vector < int>> &dp)
    {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (x[n - 1] == y[m - 1]) return dp[n][m] = 1 + recurseMemo(x, y, n - 1, m - 1, dp);
        else return dp[n][m] = max(recurseMemo(x, y, n - 1, m, dp), recurseMemo(x, y, n, m - 1, dp));
    }
};