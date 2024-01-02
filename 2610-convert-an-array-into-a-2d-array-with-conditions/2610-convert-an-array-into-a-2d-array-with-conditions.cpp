class Solution
{
    public:
        int fun(vector<int> &nums)
        {
            std::vector<std::vector < int>> res;
            for (auto i = nums.rbegin(); i != nums.rend(); ++i)
            {
                bool add = false;
                for (auto &r: res)
                {
                    if (std::find(r.begin(), r.end(), *i) == r.end())
                    {
                        r.push_back(*i);
                        add = true;
                        break;
                    }
                }
                if (!add)
                {
                    res.emplace_back(std::initializer_list < int>
                    {
                        *i });
                }
            }
            return 0;
        }
    vector<vector < int>> findMatrix(vector<int> &nums)
    {
        std::vector<std::vector < int>> res;
        for (auto i = nums.rbegin(); i != nums.rend(); ++i)
        {
            bool add = false;
            for (auto &r: res)
            {
                if (std::find(r.begin(), r.end(), *i) == r.end())
                {
                    r.push_back(*i);
                    add = true;
                    break;
                }
            }
            if (!add)
            {
                res.emplace_back(std::initializer_list < int>
                {
                    *i });
            }
        }
        return res;
    }
};