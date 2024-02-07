class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq;
        
        for(auto c:s){
            map[c]++;
        }
        for(auto it=map.begin();it!=map.end();it++){
            pq.push({it->second,it->first});
        }
        s.clear();
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            string s1 = "";
            int sz = p.first;
            while(sz--){
                s1+=p.second;
            }
            s+=s1;
            s1.clear();
        }
        return s;
    }
};