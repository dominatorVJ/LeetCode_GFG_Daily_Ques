class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int,int>> st;
        vector<int> ls,rs;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
                if(st.empty()){
                    ls.push_back(-1);
                }else{
                    ls.push_back(st.top().second);
                }
        
            st.push({arr[i],i});
        }
        while(!st.empty())
        st.pop();
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>arr[i]){
                st.pop();
            }
                if(st.empty()){
                    rs.push_back(n);
                }else{
                    rs.push_back(st.top().second);
                }
        
             st.push({arr[i],i});
        }
        reverse(rs.begin(),rs.end());
        
        int sum = 0;
        for(int i=0;i<n;i++){
            long long cnt = 1LL*(i - ls[i])*1LL*(rs[i] - i)*arr[i];
            cnt = cnt%mod;
            sum += cnt;
            sum %= mod; 
        }
        
        return sum;
    }
};