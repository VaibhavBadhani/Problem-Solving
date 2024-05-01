class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n<0) return 1e9;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i =1;i<=n;i++){
            long long x = i*i;
            ans = min(ans,1+solve(n-x,dp));
        } 
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};