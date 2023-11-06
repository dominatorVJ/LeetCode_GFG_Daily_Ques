class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mapp;
        for(int i=0;i<order.size();i++){
            mapp[order[i]] = i;
        }
        string x="",y="";
        for(int i=0;i<s.size();i++){
            if(mapp.count(s[i])){
                x+=s[i];
            }else{
                y+=s[i];
            }
        }
        priority_queue<pair<int,char>> pq;
        for(char c:x){
            pq.push({-mapp[c],c});
        }
        x.clear();
        while(!pq.empty()){
            x+=pq.top().second;
            pq.pop();
        }
        return x+y;
    }
};