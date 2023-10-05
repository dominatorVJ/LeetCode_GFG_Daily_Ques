class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            vector<int> ans;
            int n = nums.size();
            int cand1 = INT_MIN, cand2 = INT_MIN;
            int cnt1 = 0, cnt2 = 0;

            for (int i = 0; i < n; i++)
            {
                if (cand1 == nums[i]) cnt1++;
                else if (cand2 == nums[i]) cnt2++;
                else if (cnt1 == 0) cand1 = nums[i], cnt1 = 1;
                else if (cnt2 == 0) cand2 = nums[i], cnt2 = 1;
                else cnt1--, cnt2--;
            }
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == cand1) c1++;
                else if (nums[i] == cand2) c2++;
            }
            if (c1 > n / 3) ans.push_back(cand1);
            if (c2 > n / 3) ans.push_back(cand2);

            return ans;
        }
};