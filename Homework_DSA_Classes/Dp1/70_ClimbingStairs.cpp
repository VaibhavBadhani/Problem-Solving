class Solution {
public:
    int cb(int n,vector<int>& dp) {
        if( n<=0) return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cb(n-1,dp)+cb(n-2,dp);
    }
    int climbStairs(int n) {
        if(n<0) return 0;
        vector<int>dp(n+1,-1);
        return cb(n,dp);
    }
};