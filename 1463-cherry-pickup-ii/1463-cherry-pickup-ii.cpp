class Solution {
    int m,n;
    vector<vector<int>> vis;
    vector<vector<vector<int>>> dp;
    int f(vector<vector<int>> &grid,int j1,int j2,int i){
        if(j1<0 || j1==n || j2<0 || j2==n || vis[i][j1]==-1 || vis[i][j2]==-1) return -1e9;
        if(i==m-1){
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                vis[i][j1]=-1;
                vis[i][j2]=-1;
                if(j1+dj1!=j2+dj2) maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(grid,j1+dj1,j2+dj2,i+1));
                vis[i][j1]=1;
                vis[i][j2]=1;
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vis.resize(m,vector<int>(n,1));
        dp.resize(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(grid,0,n-1,0);
    }
};