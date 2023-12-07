class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int i=num.size()-1;
        while(i>=0){
           if((num[i]-'0')%2==1){
               ans+=num[i];
               break;
           } 
            i--;
        }
        i--;
        if(ans=="") return ans;
        while(i>=0){
            ans+=num[i--];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};