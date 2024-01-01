
#define f(i,a,b) for(ll i=a;i<b;i++)
#define vsort(a) sort(a.begin(),a.end())
#define vrsort(a) sort(a.begin(),a.end(),greater< ll >())
#define vll vector <ll>
#define vb vector<bool>
#define pi pair <int,int>
#define ll long long int
#define pb push_back
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int n=g.size(),m=s.size();
        vsort(g);
        vsort(s);
        ll cnt=0;
        while(i<n){
          if(j==m){
              break;
          }
          if(g[i]<=s[j]){
              i++;j++;
              cnt++;
          }else{
              j++;
          }
          
        }
        return cnt;
    }
};