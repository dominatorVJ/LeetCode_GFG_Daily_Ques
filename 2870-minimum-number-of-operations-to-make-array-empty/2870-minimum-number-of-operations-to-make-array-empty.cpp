class Solution
{
    public:
        int minOperations(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            for (int i: nums)
            {
                mp[i]++;
            }
            int cnt = 0;
            for (auto a: mp)
            {
                if (a.second == 1)
                {
                    cnt = -1;
                    break;
                }
                cnt += (a.second+3-1)/3;
            }
            return cnt;
        }
};