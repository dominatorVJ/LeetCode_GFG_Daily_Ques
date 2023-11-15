class Solution
{
    public:
        int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
        {
            sort(arr.begin(), arr.end());
            int curr = 1,cnt = 1;

            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i] >= curr + 1)
                {
                    cnt++;
                    curr = cnt;
                }
            }

            return cnt;
        }
};