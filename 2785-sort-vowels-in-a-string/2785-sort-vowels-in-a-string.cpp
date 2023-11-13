class Solution {
public:
     bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    string sortVowels(string s) {
        unordered_map<char,int> mapp;
        string sortedVowel = "AEIOUaeiou";
        int j = 0;
        string ans = "";
        for(auto c:s){
            mapp[c]++;
        }
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(mapp[sortedVowel[j]] == 0) j++;
                ans+= sortedVowel[j];
                mapp[sortedVowel[j]]--;
            }else{
               ans+=s[i]; 
            }
        }
        return ans;
    }
};