class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<int> rows1(m),rows0(m);
        vector<int> cols1(n),cols0(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++ ){
                if(grid[i][j] == 0){
                    rows0[i]++;
                    cols0[j]++;
                }else{
                     rows1[i]++;
                     cols1[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = rows1[i]+cols1[j]-rows0[i]-cols0[j];
            }
        }
        return ans;
    }
};