//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vst(n,vector<bool>(m,0));
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(mat[i][j] == 'O' && !vst[i][j]){
                        vst[i][j] = 1;
                        dfs(i,j,mat,vst);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O') 
                 if(!vst[i][j])
                mat[i][j] = 'X';
            }
        }
        return mat;
    }
    void dfs(int i,int j,vector<vector<char>>& mat,vector<vector<bool>> &vst){
        int n = mat.size();
        int m = mat[0].size();
        vst[i][j]=1;
        int dx[]={0,-1,0,+1};
        int dy[]={-1,0,+1,0};
        
        for(int k=0;k<4;k++){
            int nrow=i+dx[k];
            int ncol = j+dy[k];
            // check for valid cells
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vst[nrow][ncol] && mat[nrow][ncol] == 'O' ){
                vst[nrow][ncol]=1;
                dfs(nrow,ncol,mat,vst);
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends