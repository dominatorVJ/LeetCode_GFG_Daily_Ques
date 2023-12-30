class Solution
{
    public:
        bool makeEqual(vector<string> &words)
        {
            int n = words.size();
            unordered_map<char, int> mapp;
            for (auto s: words)
            {
                for (char c: s)
                {
                    mapp[c]++;
                }
            }
            for (auto a: mapp)
            {
                if (a.second % n != 0)
                {
                    return false;
                }
            }
            return true;
        }
};