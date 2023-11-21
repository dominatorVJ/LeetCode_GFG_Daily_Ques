//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
         // Code here
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        
        vector<vector<int>> cost(n,vector<int>(m,1e9));
        cost[0][0] = grid[0][0];
        set<pair<int,pair<int,int>>>  st;
        
        st.insert({grid[0][0],{0,0}});
            
        while(!st.empty()) {
            auto it = *(st.begin());
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            st.erase(it);
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                (wt + grid[nrow][ncol] < cost[nrow][ncol])) {
                    if(cost[nrow][ncol] != 1e9) 
                        st.erase({cost[nrow][ncol],{nrow,ncol}});
                    cost[nrow][ncol] = wt + grid[nrow][ncol];
                    st.insert({cost[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        
        
        return cost[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends