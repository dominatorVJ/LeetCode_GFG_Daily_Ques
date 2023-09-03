class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> minq,maxq;
        int s = 0, e = 0, ans = 0;
        
        while(e<n){
            int x = nums[e];
            
           while(minq.size()>0 && nums[minq.back()]>=x) minq.pop_back();
             minq.push_back(e); 
           while(maxq.size()>0 && nums[maxq.back()]<=x) maxq.pop_back(); 
             maxq.push_back(e); 
           
            int u = nums[minq.front()];
            int v = nums[maxq.front()];
            
            if(v-u<=limit) ans = max(ans,e-s+1),e++;
            else{
                s++;
                if(s>minq.front()) minq.pop_front();
                if(s>maxq.front()) maxq.pop_front();
            }
        }
        
        return ans;
    }
};