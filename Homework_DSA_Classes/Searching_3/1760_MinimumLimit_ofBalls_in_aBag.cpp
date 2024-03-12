class Solution {
public:
    bool isposs( int mid, vector<int>& nums, int op)
    {
        int count =0;
        for(int i =0;i<nums.size();i++)
        {
            count+=(nums[i]-1)/mid;
            if(count>op){
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int low = 1;
       int high = INT_MAX;
       int ans = -1;
       while(low<=high){
        int mid = low+(high-low)/2;
        if(isposs(mid,nums,maxOperations)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
       }
       return ans;
    }
};