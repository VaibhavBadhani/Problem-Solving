class Solution {
public:
    int solve(int i ,int amount , vector<int>& coins,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            return amount%coins[0]==0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int nottake = solve(i-1,amount,coins,dp);
        int take =0;
        if(coins[i]<=amount)
        {
            take = solve(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=take+nottake;
    }
    int tab(int amount, vector<int>& coins)
    {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int n = coins.size();
        for(int i =0;i<=amount;i++)
        {
             dp[0][i]= (i%coins[0]==0);
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<=amount;j++)
            {
                int nottake = dp[i-1][j];
                int take =0;
                if(coins[i]<=j)
                {
                    take = dp[i][j-coins[i]];
                }
                dp[i][j]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // return solve(coins.size()-1,amount,coins,dp);
        return tab(amount,coins);
    }
};