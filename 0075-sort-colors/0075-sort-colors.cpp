class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Approach 1 Normal Sort T.C. - O(nlogn)
        // sort(nums.begin(),nums.end());
        //Approach 2 Count Sort T.C. - O(n)
        // int cnt0 = 0,cnt1 = 0, cnt2=0;
        // for(int i:nums){
        //     if(i==0) cnt0++;
        //     else if(i==1)cnt1++;
        //     else cnt2++;
        // }
        // int i = 0;
        // while(cnt0--){
        //     nums[i++]=0;
        // }
        // while(cnt1--){
        //     nums[i++]=1;
        // }
        // while(cnt2--){
        //     nums[i++]=2;
        // }
        // Approach 3 DNF Algo
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[low++] );
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high--]);
            }
        }
        
    }
};