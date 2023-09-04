class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> ans(n);
        for(auto v:b){
            int s = v[0]-1;
            int e = v[1]-1;
            int wt = v[2];
            ans[s]+=wt;
            if(e+1<n) ans[e+1]-=wt;
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};