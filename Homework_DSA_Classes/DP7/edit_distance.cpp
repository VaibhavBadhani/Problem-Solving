

class Solution {
public:
    int rec(string w1,string w2,int i ,int j, vector<vector<int>>& dp)
    {
        
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i-1]==w2[j-1]) {
            return dp[i][j]=rec(w1,w2,i-1,j-1,dp);
        }
        else{
            int x = rec(w1,w2,i-1,j-1,dp);
            int y = rec(w1,w2,i-1,j,dp);
            int z = rec(w1,w2,i,j-1,dp);
            
            return dp[i][j]=1+min(x,min(y,z));

        }
        
    }
    int tab (string w, string t)
    {
        int n = w.length();int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                    if(w[i-1]==t[j-1]) {
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    int x = dp[i-1][j-1];
                    int y = dp[i-1][j];
                    int z = dp[i][j-1];
                    
                    dp[i][j]=1+min(x,min(y,z));

                   }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        // if(word1.length()==0)return word2.length();
        // if(word2.length()==0)return word1.length();
        // int n = word1.length();int m = word2.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return tab(word1,word2);
    }
};






