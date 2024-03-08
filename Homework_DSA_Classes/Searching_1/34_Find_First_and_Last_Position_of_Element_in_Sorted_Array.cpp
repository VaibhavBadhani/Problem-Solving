class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int m  = low+(high-low)/2;
            if(nums[m]==target){
                ans[0]= m;
                high= m-1;
            }
            else if(nums[m]<target){
                low= m+1;
            }
            else{
                high = m-1;
            }
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int m  = low+(high-low)/2;
            if(nums[m]==target){
                ans[1]= m;
                low= m+1;
            }
            else if(nums[m]<target){
                low= m+1;
            }
            else{
                high = m-1;
            }
        }
        return ans;
    }
};