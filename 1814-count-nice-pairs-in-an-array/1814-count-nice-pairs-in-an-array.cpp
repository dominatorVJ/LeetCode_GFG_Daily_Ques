class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i] - rev(nums[i]));
        }
        
        unordered_map<int, int> dic;
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int num : arr) {
            ans = (ans + dic[num]) % MOD;
            dic[num]++;
        }
        
        return ans;
    }
    
    int rev(int num) {
        string s = to_string(num);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
};