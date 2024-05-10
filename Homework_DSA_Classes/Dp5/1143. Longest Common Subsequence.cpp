class Solution {
public:
    int recursion(int i ,int j ,string t,string s){
        if(i>=t.size()||j>=s.size()) return 0;
        int take = 0;
        if(t[i]==s[j]) take = 1+recursion(i+1,j+1,t,s);
        int nottake = 0+max(recursion(i+1,j,t,s),recursion(i,j+1,t,s));
        return max(take,nottake);
    }
    int memoisation(int i ,int j ,string t,string s,vector<vector<int>>& dp){
        if(i>=t.size()||j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0;
        if(t[i]==s[j]) take = 1+memoisation(i+1,j+1,t,s,dp);
        int nottake = 0+max(memoisation(i+1,j,t,s,dp),memoisation(i,j+1,t,s,dp));
        return dp[i][j]=max(take,nottake);
    }
    int tabulation(string t, string s){
        vector<vector<int>>dp(t.size()+1,vector<int>(s.size()+1,0));
        int n = t.size();int m = s.size();
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int take = 0;
                if(t[i]==s[j]) take = 1+dp[i+1][j+1];
                int nottake = 0+max(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string t, string s) {
        vector<vector<int>>dp(t.size()+1,vector<int>(s.size()+1,-1));
        // return memoisation(0,0,t,s,dp);
        return tabulation(t,s);

    }
};









