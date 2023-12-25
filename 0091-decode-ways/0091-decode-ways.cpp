class Solution {
public:
   int dp[101];
    int util(int idx,int n,string&s)
    {
        if(idx>n)
            return 0;
        if(idx==n)
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];

        int one=0,two=0;
        if(idx<=n-1 and s.substr(idx,1)>="1" and s.substr(idx,1)<="9")
        {
            one+=util(idx+1,n,s);
        }
        if(idx<=n-2 and s.substr(idx,2)>="10" and s.substr(idx,2)<="26")
        {
            two+=util(idx+2,n,s);
        }
        return dp[idx]=one+two;
    }

    int numDecodings(string s) 
    {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return util(0,n,s);
    }
};