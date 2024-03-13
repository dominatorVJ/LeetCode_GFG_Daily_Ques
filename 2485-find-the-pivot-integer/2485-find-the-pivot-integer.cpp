class Solution {
public:
    int pivotInteger(int n) {
        int pivot = -1;
        int tsum = (n*(n+1))/2;
        int lsum = 0;
        for(int i=1;i<=n;i++){
            lsum+=i;
            if(lsum==tsum){
                pivot=i;
                break;
            }
            tsum-=i;
        }
        return pivot;
    }
};