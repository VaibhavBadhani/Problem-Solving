class Solution {
    public int search(int[] nums, int target) {
        int low=0;
        int high = nums.length-1;
               int mid;
        while(low<=high)
        {
            mid = (high+low)/2;
            if(nums[mid]==target)
            {
                 return mid;
            } 
            if(nums[mid]>=nums[low])//in upper slanting part
            {
                if(target>nums[mid]||target<nums[low]){
                    low = mid+1;
                }
                else{
                    high = mid -1;
                }
            }
            else{
                if(target<nums[mid]||target>nums[high]){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            


        }
        return -1;
    }
}




















