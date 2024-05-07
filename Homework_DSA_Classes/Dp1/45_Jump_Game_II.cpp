// class Solution {
// public:
//     long long int solve(vector<int>& nums,int i,long long int jumps,vector<int>& dp){
//         if(i>=nums.size()-1){
//             return 0;
//         }
//         if(dp[i]!=-1) return dp[i];
//         for(int ind =1;ind<=nums[i];ind++){
//             jumps =min(jumps,1+solve(nums,i+ind,jumps,dp));
//         }
//         return dp[i]=jumps;
//     }
//     int jump(vector<int>& nums) {
//         long long int jumps =INT_MAX;
//         vector<int>dp(nums.size()+1,-1);
//         return solve(nums,0,jumps,dp);
//     }
// };
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
    int tabulation(vector<int>& nums){
        vector<int>dp(100000,1e5);
        for(int i =nums.size()-1;i>=0;i--){
            for(int ind =1;ind<=nums[i];ind++){
                if(i+ind>=nums.size()-1){
                    dp[i]=1;
                }
                else dp[i] = min(dp[i],1+dp[i+ind]);
            }
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) { return 0;
        }
        long long int jumps =INT_MAX;
        // vector<int>dp(nums.size()+1,-1);
        // return solve(nums,0,jumps,dp);
        return tabulation(nums);
    }
};