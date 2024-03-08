class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high = nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid = (high+low)/2;
            if(nums[mid]==target)
            {
                 return true;
            } 
            if(nums[mid]>nums[low])
            {
                if(target>nums[mid]||target<nums[low])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else if(nums[mid]<nums[low])
            {
                if(target<nums[mid]||target>nums[high])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                low++;
            }


        }
        return false;
    }
};
