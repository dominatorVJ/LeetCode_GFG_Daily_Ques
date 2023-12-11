class Solution
{
    public:
        int findSpecialInteger(vector<int> &arr)
        {
            unordered_map<int, int> mp;
            for (int i: arr)
            {
                mp[i]++;
            }
            int maxi = 0, ans = 0;
            for (auto a: mp)
            {
                if (a.second > maxi)
                {
                    maxi = a.second;
                    ans = a.first;
                }
            }
            return ans;
        }
};