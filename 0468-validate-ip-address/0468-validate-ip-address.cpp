class Solution {
public:
    bool checkforIPv6(string IP){
        IP.push_back(':');
        int n = IP.size();
        vector<string>store;
        string s = "";
        for(int i=0; i<n; i++){
            if(IP[i] == ':'){
                store.push_back(s);
                s = "";
            }
            else{
                s+=IP[i];
            }
        }
        if(store.size() != 8){
            return false;
        }
        for(int i=0; i<store.size(); i++){
            string s = store[i];
            if(s.size() > 4 || s.size() == 0){
                return false;
            }
            for(int j=0; j<s.size(); j++){
                if(s[j] >= 'a' && s[j] <= 'f'){
                    continue;
                }
                else if(s[j] >= 'A' && s[j] <= 'F'){
                    continue;
                }
                else if(s[j] >= '0' && s[j] <= '9'){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkforIPv4(string IP){
        IP.push_back('.');
        int n = IP.size();
        vector<string>store;
        string s = "";
        for(int i=0; i<n; i++){
            if(IP[i] == '.'){
                store.push_back(s);
                s = "";
            }
            else{
                s+=IP[i];
            }
        }
        if(store.size() != 4){
            return false;
        }
        for(int i=0; i<store.size(); i++){
            string s = store[i];
            if(s.size() > 3 || s.size() == 0){
                return false;
            }
            if(s.size() >= 2 && s[0] == '0' && s[1] == '0'){
                return false;
            }
            if(s.size() >= 2 && s[0] == '0' && s[1] != '0'){
                return false;
            }
            int num = 0;
            for(int j=0; j<s.size(); j++){
                if(s[j] >= '0' && s[j] <= '9'){
                    num = num*10 + (s[j]-'0');
                }
                else{
                    return false;
                }
            }
            if(num > 255 || num < 0){
                return false;
            }
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        bool IPv6 = checkforIPv6(queryIP);
        bool IPv4 = checkforIPv4(queryIP);
        if(IPv6){
            return "IPv6";
        }
        if(IPv4){
            return "IPv4";
        }
        return "Neither";
    }
};