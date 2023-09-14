class Solution
{
    public:
        int numSubarraysWithSum(vector<int> &nums, int goal)
        {
            unordered_map<int, int> mapp;
            int sum = 0;
            mapp[sum] = 1;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                int rsum = sum - goal;
                if (mapp.count(rsum))
                {
                    cnt += mapp[rsum];
                }
                mapp[sum]++;
            }
            return cnt;
        }
};