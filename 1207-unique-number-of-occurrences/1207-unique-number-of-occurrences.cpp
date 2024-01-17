class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            unordered_map<int, int> mp;
            unordered_set<int> st;
            for (auto i: arr) mp[i]++;
            for (auto a: mp) st.insert(a.second);

            return mp.size() == st.size();
        }
};