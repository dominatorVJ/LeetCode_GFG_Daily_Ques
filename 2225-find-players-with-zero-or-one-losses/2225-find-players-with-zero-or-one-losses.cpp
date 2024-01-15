class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &matches)
        {
            unordered_map<int, int> win, lose;
            for (auto a: matches)
            {
                win[a[0]]++;
                lose[a[1]]++;
            }
            vector<vector < int>> ans;
            vector<int> A, B;
            for (auto a: win)
            {
                if (lose[a.first] == 0)
                {
                    A.push_back(a.first);
                }
            }
            for (auto b: lose)
            {
                if (lose[b.first] == 1)
                {
                    B.push_back(b.first);
                }
            }
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            ans.push_back(A);
            ans.push_back(B);
            return ans;
        }
};