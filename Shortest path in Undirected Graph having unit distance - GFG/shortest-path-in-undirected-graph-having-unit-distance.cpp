//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> adj[n];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dista(n,-1);
        vector<bool> vis(n,0);
        queue<pair<int,int>> q;
        q.push({src,0}); //src
        vis[src]=1;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            int node = x.first;
            int dist = x.second;
            dista[node] = dist;
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dist+1});
                }
            }
        }
        return dista;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends