class Solution
{
    public:
        vector<int> numberGame(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(n);
            vector<int> alice, bob;
            int j = 0, k = 0;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    alice.push_back(nums[i]);
                }
                else
                {
                    bob.push_back(nums[i]);
                }
            }
            bool flag = 1;
            for (int i = 0; i < n; i++)
            {
                if (flag)
                {
                    ans[i] = bob[j++];
                }
                else
                {
                    ans[i] = alice[k++];
                }
                flag = !flag;
            }
            return ans;
        }
};