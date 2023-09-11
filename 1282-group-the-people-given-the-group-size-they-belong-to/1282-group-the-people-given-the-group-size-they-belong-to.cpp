class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &v)
        {
            vector<vector < int>> ans;
            unordered_map<int, vector < int>> mapp;

            for (int i = 0; i < v.size(); i++)
            {
                mapp[v[i]].push_back(i);
                if (v[i] == mapp[v[i]].size())
                {
                    ans.push_back(mapp[v[i]]);
                    mapp.erase(mapp.find(v[i]));
                }
            }
            return ans;
        }
};