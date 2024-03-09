class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int  ans =-1;

        while(low<=high){
            if(low==high) return nums[low];
            int mid = low+(high-low)/2;
            if(mid%2!=0){
                if(nums[mid]==nums[mid-1]){
                    low= mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    low = mid+2;
                }
                else{
                    ans= mid;
                    high = mid;
                }
            }
        }
        return nums[ans];
    }
};