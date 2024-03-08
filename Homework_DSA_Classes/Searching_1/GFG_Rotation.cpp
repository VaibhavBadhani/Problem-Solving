class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int low = 0;
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
        return ans;

	}

};