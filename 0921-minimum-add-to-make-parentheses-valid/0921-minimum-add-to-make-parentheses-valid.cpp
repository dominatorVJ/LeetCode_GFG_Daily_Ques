class Solution {
public:
    int minAddToMakeValid(string s) {
       int cl = 0;
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i] == '('){
                st.push(s[i]);
                i++;
            }else{
             if(!st.empty()){
                if(st.top() == '(')
                    st.pop(),
                    i++;
            }else{
                   cl++;
                   i++;
                }
            }
        }
        return cl+st.size();
    }
};