class Solution {
public:
    // int solve(int i ,int j ,int m , int n,vector<vector<int>>&dp){
    //     if(i==(m-1)&&j==(n-1)) return 1;
    //     if(j>=n||i>=m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = solve(i+1,j,m,n,dp);
    //     int right = solve(i,j+1,m,n,dp);
    //     return dp[i][j]=down+right;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                i
                 if(i==0&&j==0) dp[i][j]=1;
                else{
                    int down =0;
                    int right =0;
                    if(i>0)down = dp[i-1][j];
                    if(j>0)right = dp[i][j-1];
                    dp[i][j]=down+right;
                }
            }
        }
        return dp[m-1][n-1];

    }
};
