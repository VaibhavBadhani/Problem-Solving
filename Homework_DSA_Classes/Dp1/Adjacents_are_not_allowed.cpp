// public:
//     int solve(int i ,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
//         if(i>= mat[0].size()) return 0;
//         if(dp[j][i]!=-1) return dp[j][i];
//         int t1=0,t2=0;
//         t1= mat[j][i]+max(solve(i+2,0,mat,dp),solve(i+2,1,mat,dp));
        
//         t2= 0+max(solve(i+1,0,mat,dp),solve(i+1,1,mat,dp));
//         return dp[j][i]=max(t1,t2);
//     }
//     int maxSum(int N, vector<vector<int>> mat)
//     {
//         vector<vector<int>>dp1(3,vector<int>(mat[0].size()+1,-1));
//         vector<vector<int>>dp2(3,vector<int>(mat[0].size()+1,-1));
//         return max(solve(0,0,mat,dp1),solve(0,1,mat,dp2));
//     }
// };
tabulationtabulationclass Solution{
public:
    int solve(int i ,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i>= mat[0].size()) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int t1=0,t2=0;
        t1= mat[j][i]+max(solve(i+2,0,mat,dp),solve(i+2,1,mat,dp));
        
        t2= 0+max(solve(i+1,0,mat,dp),solve(i+1,1,mat,dp));
        return dp[j][i]=max(t1,t2);
    }
    int tabulation(int i ,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i>= mat[0].size()) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int t1=0,t2=0;
        t1= mat[j][i]+max(solve(i+2,0,mat,dp),solve(i+2,1,mat,dp));
        
        t2= 0+max(solve(i+1,0,mat,dp),solve(i+1,1,mat,dp));
        return dp[j][i]=max(t1,t2);
    }
    int tabulation(int N, vector<vector<int>> mat)
   {
          vector<int> v1;
          vector<int> v2;
          for(int i=0;i<N;i++)
          {
              v1.push_back(mat[0][i]);
              
          }
          for(int i=0;i<N;i++)
          {
              v2.push_back(mat[1][i]);
          }
          vector<int> dp(N);
          dp[0]=max({v1[0],v2[0]});
          dp[1]=max({v1[1],v2[1],v1[0],v2[0]});
          for(int i=2;i<N;i++)
          {
              dp[i]=max( { ( max({v1[i],v2[i]})+dp[i-2]  ), dp[i-1] });
          }
          return dp[N-1];  
   }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // vector<vector<int>>dp1(3,vector<int>(mat[0].size()+1,-1));
        // vector<vector<int>>dp2(3,vector<int>(mat[0].size()+1,-1));
        // return max(solve(0,0,mat,dp1),solve(0,1,mat,dp2));
        return tabulation(N,mat);
    }