class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
       
         int l = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
	     int u = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
	     if(!binary_search(arr.begin(),arr.end(),x)) return {-1,-1};
	    return {l,u-1};
    }
};