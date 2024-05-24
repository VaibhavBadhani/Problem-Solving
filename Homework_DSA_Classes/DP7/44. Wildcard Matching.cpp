class Solution {
public:
    // int solve(string s,string p,int i, int j ,vector<vector<int>>& dp)
    // {
    //     if(i==0&&j==0)return true;
    //     if(i==0&j>0) return false;
    //     if(j==0&i>0)
    //     {
    //         for(int k =1;k<=i;k++)
    //         {
    //             if(p[k-1]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(p[i-1]==s[j-1]||p[i-1]=='?')
    //     {
    //         return dp[i][j]=solve(s,p,i-1,j-1,dp);
    //     }
    //     if(p[i-1]=='*')
    //     {
    //         return dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp); 
    //     }
    //     return dp[i][j]=false;
    // }
    bool isMatch(string s, string p) {
        int m  = s.length();
        int n = p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]= true;
        for(int j =0;j<=m;j++)
        {
            dp[0][j]=false;
        }for(int i =1;i<=n;i++)
        {
            int f1= true;
            for(int k =1;k<=i;k++)
            {
                if(p[k-1]!='*'){
                    f1=false;
                    break;
                }
            }
            dp[i][0]=f1;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                if(p[i-1]==s[j-1]||p[i-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*')
                {
                    dp[i][j]= dp[i-1][j] || dp[i][j-1]; 
                }
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
};







