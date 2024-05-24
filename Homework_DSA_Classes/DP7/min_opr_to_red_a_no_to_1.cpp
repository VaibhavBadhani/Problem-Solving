
int recur(int x)
{
    if (x == 1)
        return 0;
    int a = INT_MAX;
    int b = INT_MAX;
    int c = steps(x - 1);
    if (x % 2 == 0)  a = steps(x / 2);
    if (x % 3 == 0)  b = steps(x / 3);
    return 1 + min(a, min(b, c));
}

int memo(int x, int dp[])
{
    if (x < 2)
        return 0;
    dp[2] = 1;
    dp[3] = 1;
    if (dp[x]!=-1) return dp[x];
    int a = INT_MAX;
    int b = INT_MAX;
    int c = steps(x - 1, dp);
    if (x % 2 == 0) a = steps(x / 2, dp);
    if (x % 3 == 0) b = steps(x / 3, dp);
    dp[x] = 1 + min(a, min(b, c));
}

int stepsBU(int x)
{
    vector<int>dp(x,0);
    if (x < 2)
        return 0;
    int dp[x + 1];
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= x; i++)
    {
        int a = INT_MAX;
        int b = INT_MAX;
        int c = dp[i - 1];
        if (i % 2 == 0) a = dp[i / 2];
        if (i % 3 == 0) b = dp[i / 3];
        dp[i] = 1 + min(a, min(b, c));
    }
    return dp[x];
}