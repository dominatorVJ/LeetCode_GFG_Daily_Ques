class Solution
{
    public:
        int numberOfBeams(vector<string> &bank)
        {
            int res = 0, prev = 0;
            for (auto s: bank)
            {
                int curr = 0;
                for (auto c: s)
                {
                    if (c == '1')
                    {
                        curr++;
                    }
                }
                if (curr != 0)
                {
                    res += (curr *prev);
                    prev = curr;
                }
            }
            return res;
        }
};