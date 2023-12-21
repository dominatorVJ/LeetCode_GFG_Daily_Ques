class Solution
{
    public:
        int maxWidthOfVerticalArea(vector<vector < int>> &p)
        {
            int maxi = INT_MIN;
            sort(p.begin(), p.end());
            for (int i = 1; i < p.size(); i++)
            {
                int diffx = p[i][0] - p[i - 1][0];
                maxi = max(maxi, diffx);
            }

            return maxi;
        }
};