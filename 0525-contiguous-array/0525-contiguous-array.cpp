class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxx=0,sum=0;
        map[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) sum+=-1;
            else sum+=1;
            if(map.count(sum)){
                int len = i-map[sum];
                maxx=max(maxx,len);
            }else{
                map[sum]=i;
            }
        }
        return maxx;
    }
};