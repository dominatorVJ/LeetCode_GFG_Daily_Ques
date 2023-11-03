class Solution
{
    public:
        vector<string> buildArray(vector<int> &target, int n)
        {
            vector<string> ans;
            vector<int> stream(n + 1);
            for (int i = 1; i <= n; i++)
            {
                stream[i] = i;
            }
            stack<int> st;
            int j = 0;
            int i = 1;
            while (j < target.size())
            {
                if (target[j] == stream[i])
                {
                    while (j > 0 && target[j - 1] != st.top())
                    {
                        ans.push_back("Pop");
                        st.pop();
                    }
                    if (j - 1 < 0)
                    {
                        while (!st.empty())
                        {
                            ans.push_back("Pop");
                            st.pop();
                        }
                    }
                    st.push(stream[i]);
                    ans.push_back("Push");
                    i++;
                    j++;
                }
                else
                {
                    st.push(stream[i]);
                    ans.push_back("Push");
                    i++;
                }
            }

            return ans;
        }
};