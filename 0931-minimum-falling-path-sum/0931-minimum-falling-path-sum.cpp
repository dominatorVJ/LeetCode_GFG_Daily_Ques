class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &mat)
        {
            int n = mat.size();
            int dp[n][n];

            for (int j = 0; j < n; j++)
            {
                dp[0][j] = mat[0][j];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j == 0)
                    {
                        dp[i][j] = mat[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                    }
                    else if (j == n - 1)
                    {
                        dp[i][j] = mat[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                    }
                    else
                    {
                        dp[i][j] = mat[i][j] + min({ dp[i - 1][j],
                            dp[i - 1][j - 1],
                            dp[i - 1][j + 1] });
                    }
                }
            }
            int mini = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                mini = min(dp[n - 1][i], mini);
            }

            return mini;
        }
};