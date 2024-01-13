class Solution
{
    public:
        int minSteps(string s, string t)
        {
            unordered_map<char, int> mp1;
            unordered_map<char, int> mp2;
            for (auto c: s)
            {
                mp1[c]++;
            }
            for (auto c: t)
            {
                mp2[c]++;
            }
            int cnt = 0;
            int cnt2 = 0;
            for (auto a: mp1)
            {
                char c = a.first;
                if (mp2.count(a.first))
                {
                    if (mp2[c] < mp1[c])
                    {
                        cnt += mp1[c] - mp2[c];
                    }
                }
                else
                {
                    cnt += mp1[c];
                }
            }
            return cnt;
        }
};