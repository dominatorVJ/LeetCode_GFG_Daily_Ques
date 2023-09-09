class Solution
{
    public:

        vector<vector < int>> combinationSum2(vector<int> &arr, int t)
        {
            sort(arr.begin(), arr.end());
            vector<vector < int>> ans;
            vector<int> v;
            combinations(ans, v, arr, t, 0);
            return ans;
        }
    void combinations(vector<vector < int>> &ans, vector< int > v, vector< int > &arr, int t, int idx)
    {
        if (t == 0)
        {
            ans.push_back(v);
            return;
        }
        if (t < 0) return;
        for (int i = idx; i < arr.size(); i++)
        {

            if (i && arr[i] == arr[i - 1] && i > idx) continue;
            v.push_back(arr[i]);
            combinations(ans, v, arr, t - arr[i], i + 1);
            v.pop_back();
        }
    }
};