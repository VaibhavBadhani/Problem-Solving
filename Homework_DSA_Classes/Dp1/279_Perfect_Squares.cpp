// class Solution {
// public:
//     int solve(int n,vector<int>& dp){
//         if(n==0) return 0;
//         if(n<0) return 1e9;
//         if(dp[n]!=-1) return dp[n];
//         int ans = INT_MAX;
//         for(int i =1;i<=n;i++){
//             long long x = i*i;
//             ans = min(ans,1+solve(n-x,dp));
//         } 
//         return dp[n]=ans;
//     }
//     int numSquares(int n) {
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }
// };
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
    int tabulation(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int ind=1;ind<=n;ind++){
            for(int i =1;i<=n;i++){
                long long x = i*i;
                if(ind-x>=0)
                dp[ind] = min(dp[ind],1+dp[ ind-x ]);
            } 
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n,dp);
        return tabulation(n);
    }
};