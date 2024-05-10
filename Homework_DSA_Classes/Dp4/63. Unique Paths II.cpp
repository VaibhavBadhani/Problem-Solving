class Solution {
public:
    // int solve(int i ,int j ,int m , int n,vector<vector<int>>& og,vector<vector<int>>&dp){
    //         if(i==(m-1)&&j==(n-1)) return 1;
    //         if(j>=n||i>=m||og[i][j]==1) return 0;
    //         if(dp[i][j]!=-1) return dp[i][j];
    //         int down = solve(i+1,j,m,n,og,dp);
    //         int right = solve(i,j+1,m,n,og,dp);
    //         return dp[i][j]=down+right;
    //     }
    int mod = 2e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        if(og[og.size()-1][og[0].size()-1]==1) return 0;
        vector<vector<int>>dp(og.size()+1,vector<int>(og[0].size()+1,0));
        for(int i =0;i<og.size();i++){
            for(int j =0;j<og[0].size();j++){
                if(og[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0)dp[i][j]=1;
                else{
                    int down =0;
                    int right =0;
                    if(i>0)down = dp[i-1][j];
                    if(j>0)right = dp[i][j-1];
                    dp[i][j]=(down+right)%mod;
                }
            }
        }
        return (dp[og.size()-1][og[0].size()-1])%mod;
    }
};