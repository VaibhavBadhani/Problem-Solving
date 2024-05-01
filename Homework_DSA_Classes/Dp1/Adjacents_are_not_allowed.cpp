public:
    int solve(int i ,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i>= mat[0].size()) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int t1=0,t2=0;
        t1= mat[j][i]+max(solve(i+2,0,mat,dp),solve(i+2,1,mat,dp));
        
        t2= 0+max(solve(i+1,0,mat,dp),solve(i+1,1,mat,dp));
        return dp[j][i]=max(t1,t2);
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<vector<int>>dp1(3,vector<int>(mat[0].size()+1,-1));
        vector<vector<int>>dp2(3,vector<int>(mat[0].size()+1,-1));
        return max(solve(0,0,mat,dp1),solve(0,1,mat,dp2));
    }
};