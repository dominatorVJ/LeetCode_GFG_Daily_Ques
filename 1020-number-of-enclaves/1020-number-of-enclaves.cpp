class Solution
{
    public:
        int numEnclaves(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    {
                        if (grid[i][j] == 1)
                        {
                            dfs(grid, i, j);
                        }
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    void dfs(vector<vector < int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = { 1,0,-1,0};
        int dy[4] = { 0,1,0,-1};
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
        {
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 1)
            {
                dfs(grid, new_x, new_y);
            }
        }
    }
};