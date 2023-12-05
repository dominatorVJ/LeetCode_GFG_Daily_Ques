class Solution {
public:
    int ans = 0;
    int numberOfMatches(int n) {
        func(n);
        return ans;
    }
    void func(int n){
        if(n<=1) return;
        if(n%2==0){
            ans+=n/2;
            func(n/2);
        }else{
            ans+=1+(n-1)/2; 
            func((n-1)/2);
        }
    }
};