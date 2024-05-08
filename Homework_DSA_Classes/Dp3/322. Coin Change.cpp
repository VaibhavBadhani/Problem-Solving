class Solution {
public:
    int solve(int i , vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(i>=coins.size()||amount<0){
            return 1e7;
        }
        if(amount==0){
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take = 1+solve(i,coins,amount-coins[i],dp);
        int ntake = solve(i+1,coins,amount,dp);
        return dp[i][amount]=min(take,ntake);
    }
    in   int tab(vector<int>& coins, int amount)
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        int n =coins.size();
         for(int i =0;i<=amount;i++)
         {
             if(i%coins[0]==0) dp[0][i]= i/coins[0];
             else dp[0][i]= 1e9;
         }
         for(int i =1;i<n;i++)
         {
             for(int j=0;j<=amount;j++)
             {
                int notake = 0+dp[i-1][j];
                int take=INT_MAX;;
                if(coins[i]<=j)
                {
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j]= min(notake ,take);
             }
         }
         return dp[n-1][amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount,dp);
        return ans==1e7?-1:ans;
    }
};