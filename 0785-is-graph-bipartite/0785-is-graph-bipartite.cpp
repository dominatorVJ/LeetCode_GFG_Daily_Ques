class Solution
{
    public:
        bool isBipartite(vector<vector < int>> &graph)
        {
            int n = graph.size();
            vector<int> col(n, -1);
            for (int i = 0; i < n; i++)
            {
                if (col[i] == -1)
                {
                    col[i] = 0;
                    if (!dfs(graph, i, col))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    bool dfs(vector<vector < int>> &graph, int s, vector< int > &col)
    {

        for (int v: graph[s])
        {
            if (col[v] == col[s])
            {
                return 0;
            }
            else if (col[v] == -1)
            {
                col[v] = 1 ^ col[s];
                if (!dfs(graph, v, col))
                {
                    return false;
                }
            }
        }

        return true;
    }
};