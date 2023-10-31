class Solution
{
    public:
        vector<int> findArray(vector<int> &pref)
        {
           	//(v[0]^v[0])^(v[1]^v[1])^...^(v[i-1]^v[i-1])^v[i] => 0^0^...^0^v[i] => v[i]
            vector<int> v(size(pref));
            v[0] = pref[0];
            for (int i = 1; i < size(pref); i++)
            {
                v[i] = pref[i] ^ pref[i - 1];
            }
            return v;
        }
};