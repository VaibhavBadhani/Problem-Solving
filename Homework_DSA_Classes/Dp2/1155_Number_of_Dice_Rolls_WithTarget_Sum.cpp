
class Solution {
public:
   const int mod = (int)pow(10, 9) + 7; 
    int solve(int n ,int k ,int t,vector<vector<int>>& dp){
        if (t == 0 && n == 0) return 1;
        if (n == 0 || t <= 0) return 0;
        if(dp[n][t]!=-1) return dp[n][t]%mod;
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,t-i,dp))%mod;
        }
        dp[n][t]=(ans%mod);
        return dp[n][t];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n,k,target,dp);
    }
};