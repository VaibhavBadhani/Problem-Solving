class Solution {
public:
    int solve(vector<int>& nums,int i ,int n,vector<int>&dp)
    {
        if(i>n) return 0;
        if(i==n)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int inc = nums[i]+solve(nums,i+2,n,dp);
        int exe = solve(nums,i+1,n,dp);
        dp[i]=max(inc,exe);
        return dp[i]; 
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        int res2 = solve(nums,1,nums.size()-1,dp1);
        int res1 = solve(nums,0,nums.size()-2,dp2);
        
        return max(res1,res2);
    }
};