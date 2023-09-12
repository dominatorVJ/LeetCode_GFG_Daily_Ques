class Solution
{
    public:
        int minDeletions(string s)
        {
            unordered_map<char, int> mp;
            for (auto c: s)
            {
                mp[c]++;
            }
            int cnt = 0;
            unordered_set<int> st;
            for (auto a: mp)
            {
                int freq = a.second;
                if (!st.count(freq))
                {
                    st.insert(freq);
                }
                else
                {
                    while (st.count(freq) && freq > 0)
                    {
                        cnt++, freq--;
                    }
                    if (freq > 0) st.insert(freq);
                }
            }
            return cnt;
        }
};