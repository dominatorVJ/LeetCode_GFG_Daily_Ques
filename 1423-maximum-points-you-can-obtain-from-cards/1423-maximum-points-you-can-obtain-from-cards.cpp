class Solution
{
    public:
        int maxScore(vector<int> &v, int k)
        {
            int n = v.size();
            for (int i = 1; i < n; i++)
            {
                v[i] += v[i - 1];
            }
            int r = n - k - 1;	// end index 
            int i = 0;	//start index
            int t_sum = v[n - 1];
            if (n <= k)
            {
                return t_sum;
            }
            int c_sum = 0;
            int maxi = INT_MIN;
            while (r < n)
            {

                if (i == 0)
                {
                    c_sum = v[r];
                    r++;
                    i++;
                }
                else
                {
                    c_sum = v[r] - v[i - 1];
                    r++;
                    i++;
                }
                maxi = max(maxi, t_sum - c_sum);
            }
            return maxi;
        }
};