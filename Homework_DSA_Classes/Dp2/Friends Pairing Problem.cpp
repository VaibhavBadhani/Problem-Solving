#define ll long long
class Solution
{
public:
    int m=1000000007;
    ll solve(int i,int n,vector<int>& dp){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        ll t = ((i)*solve(i+2,n,dp))%m;
        ll nt = solve(i+1,n,dp)%m;
        return dp[i]=((nt+t)%m);
        
    }
    int countFriendsPairings(int n) 
    { 
        vector<int>dp(n+1,-1);
        return solve(1,n,dp);
    }
};    