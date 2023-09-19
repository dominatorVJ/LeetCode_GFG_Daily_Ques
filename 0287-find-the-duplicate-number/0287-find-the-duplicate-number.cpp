class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            int cidx = nums[i]-1;
            if(nums[i] != nums[cidx]){
                swap(nums[i],nums[cidx]);
            }else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return nums[i];
            }
        }
        return -1;
    }
};