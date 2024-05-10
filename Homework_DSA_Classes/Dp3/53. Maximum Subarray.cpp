class Solution {
public:
int vaal  ;
    int ans(vector<int>&nums,int n,vector<int>& dp){
        if(n==1) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int as = max(nums[n-1],nums[n-1]+ans(nums,n-1,dp));
        vaal = max(vaal,as);
        return dp[n]=as;
    }
    int maxSubArray(vector<int>& nums) {
    if(nums.size()==1) return nums[0];
    vector<int>dp(nums.size()+1,-1);
    vaal = nums[0];
    ans(nums,nums.size(),dp);
    return vaal;
    }
};












//  /*kdane*/ 
//         int maxi = INT_MIN;
//         int sum = 0;
//         for(int i =0;i<nums.size();i++){
//             sum+=nums[i];
//             maxi = max(maxi,sum);
//             if(sum<0) sum =0;
//         }
//         return maxi;








class Solution {
public:
int vaal  ;
    // int ans(vector<int>&nums,int n,vector<int>& dp){
    //     if(n==1) return nums[0];
    //     if(dp[n]!=-1) return dp[n];
    //     int as = max(nums[n-1],nums[n-1]+ans(nums,n-1,dp));
    //     vaal = max(vaal,as);
    //     return dp[n]=as;
    // }
    int maxSubArray(vector<int>& nums) {
    // if(nums.size()==1) return nums[0];
    // vector<int>dp(nums.size()+1,-1);
    // vaal = nums[0];
    // ans(nums,nums.size(),dp);
    // return vaal;
        vector<int>dp(nums.size()+1);
        int ans = nums[0];
        dp[0]=nums[0];
        for(int i =1;i<nums.size();i++){
            dp[i]= max(dp[i-1]+nums[i],nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};












//  /*kdane*/ 
//         int maxi = INT_MIN;
//         int sum = 0;
//         for(int i =0;i<nums.size();i++){
//             sum+=nums[i];
//             maxi = max(maxi,sum);
//             if(sum<0) sum =0;
//         }
//         return maxi;



























