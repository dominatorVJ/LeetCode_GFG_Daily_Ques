class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        unordered_set<char> st = { 'a','e','i','o','u'};
        int cnt = 0, maxi = 0;
        for(int i=0;i<k;i++){
            if(st.count(s[i])) cnt++;
        }
       
        maxi = max(cnt,maxi);
        for(int i=k;i<n;i++){
            if(st.count(s[i-k])) cnt--;
            if(st.count(s[i])) cnt++;
            maxi = max(cnt,maxi);
        }
        return maxi;
    }
};