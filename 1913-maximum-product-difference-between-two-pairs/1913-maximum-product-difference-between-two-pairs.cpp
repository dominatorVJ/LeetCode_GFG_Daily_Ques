class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi = 0,s_maxi = 0;
        int mini = INT_MAX,s_mini = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                s_maxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i]>s_maxi){
                s_maxi = nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                s_mini = mini;
                mini = nums[i];
            }
            else if(nums[i]<s_mini){
                s_mini = nums[i];
            }
        }
       
        return maxi*s_maxi - mini*s_mini;
    }
};