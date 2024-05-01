class Solution {
public:
    long long int solve(vector<int>& nums,int i,long long int jumps,vector<int>& dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        for(int ind =1;ind<=nums[i];ind++){
            jumps =min(jumps,1+solve(nums,i+ind,jumps,dp));
        }
        return dp[i]=jumps;
    }
    int jump(vector<int>& nums) {
        long long int jumps =INT_MAX;
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,jumps,dp);
    }
};