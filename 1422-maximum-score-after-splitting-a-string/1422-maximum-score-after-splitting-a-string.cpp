class Solution
{
    public:
        int maxScore(string s)
        {
            int cnt1 = 0;
            int cnt0 = 0;
            int ans = 0;
            for (char c: s)
            {
                if (c == '1') cnt1++;
            }
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == '1') cnt1--;
                else cnt0++;

                ans = max(ans, cnt1 + cnt0);
            }

            return ans;
        }
};