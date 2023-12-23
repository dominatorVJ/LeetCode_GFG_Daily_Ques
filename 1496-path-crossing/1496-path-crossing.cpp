class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> mp;
        mp['N'] = {0, 1};
        mp['S'] = {0, -1};
        mp['W'] = {-1, 0};
        mp['E'] = {1, 0};
        
        unordered_set<string> vst;
        vst.insert("0,0");
        
        int x = 0;
        int y = 0;
        
        for (char c : path) {
            auto curr = mp[c];
            int dx = curr.first;
            int dy = curr.second;
            x += dx;
            y += dy;
            
            string hash = to_string(x) + "," + to_string(y);
            if (vst.find(hash) != vst.end()) {
                return true;
            }
            
            vst.insert(hash);
        }
        
        return false;
    }
};