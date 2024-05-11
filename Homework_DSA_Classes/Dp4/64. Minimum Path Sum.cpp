class Solution {
public:
    // int solve(int i ,int j,int n,int m ,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //     if(i==0&&j==0) return grid[0][0];
    //     if(i<0||j<0) return 1e6;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = grid[i][j]+solve(i-1,j,n,m,grid,dp);
    //     int right = grid[i][j]+solve(i,j-1,n,m,grid,dp);
    //     return dp[i][j]=min(down,right);
    // }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]= grid[0][0];
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0&&j==0) dp[i][j]= grid[0][0];
                else{
                    int right =0;
                    int down =0;
                    if(i>0) down = grid[i][j]+dp[i-1][j];
                    else    down = 1e7;
                    if(j>0) right = grid[i][j]+dp[i][j-1];
                    else    right = 1e7;
                    dp[i][j]=min(down,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};