class Solution {
public:
    int findMin(vector<int>& nums) {
    
        /// brutweeeeeeeeeeeeee>>>>>>>>>>
        //  int ans = 0;
        // for(int i =0;i<nums.size()-1;i++){
        //     if(nums[i]>nums[i+1]){
        //         return nums[i+1];
        //     }

        // }
        // return nums[0];

        
        //***optimizedd      **//


        int low = 0;
        int n = nums.size();
        int high = n-1;
        int ans = 0;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<nums[high]){
                ans = mid;
                high = mid;
            }
            if(nums[mid]>nums[high]){
                ans = high;
                low= mid+1;
            }
        }
        return nums[ans];

    }
};