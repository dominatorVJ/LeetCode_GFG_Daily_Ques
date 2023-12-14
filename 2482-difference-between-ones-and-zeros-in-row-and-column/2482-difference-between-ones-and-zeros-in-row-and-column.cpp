/*
Simply evaluate no of 1's in row and col by taking the sum of the row and col.
Then evaluate the diff matrix.
To evaluate 0's count, subtract sum from the size of the row or col
so total value of diff[i][j] = row[i] + col[j] - (grid.size()- row[i]) - (grid[0].size() - col[j]) 
above equation can be simplified as : diff[i][j] = 2*row[i] + 2*col[j] - grid.size() - grid[0].size();
*/

class Solution
{
    public:
        vector<vector < int>> onesMinusZeros(vector<vector < int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> row(m);
            vector<int> col(n);
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    row[i] += grid[i][j];
                    col[j] += grid[i][j];
                }
            }
            vector<vector < int>> diff(m, vector<int> (n, 0));
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    diff[i][j] = 2 *row[i] + 2 *col[j] - m - n;
                }
            }
            return diff;
        }
};