class Solution
{
    public:
        bool canFinish(int n, vector<vector < int>> &pre)
        {
            vector<bool> path(n, 0);
            vector<bool> vis(n, 0);

            vector<vector < int>> adj(n);
            //make the adjacency list
            for (auto v: pre)
            {
                int x = v[0];
                int y = v[1];
                adj[y].push_back(x);
            }
            // Check for cycle in the directed graph
            for (int i = 0; i < n; i++)
            {
                if (!vis[i] && cyclePresent(i, adj, vis, path))
                {
                    return 0;
                }
            }
            return 1;
        }
    bool cyclePresent(int i, vector<vector < int>> &adj, vector< bool > &vis, vector< bool > &path)
    {
        //check if the node is present in the current path or not if yes => cycle present
        path[i] = 1;
        vis[i] = 1;
        for (auto it: adj[i])
        {
            if (path[it]) return true; // if already traversed and encountered again
            if (!vis[it] && cyclePresent(it, adj, vis, path))
            {
                return 1;
            }
        }
        path[i] = 0;
        return 0;
    }
};