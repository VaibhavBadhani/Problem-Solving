class Solution {
public:
    int solve(string s, int i ,vector<int>& dp)
    {
        if(i>=s.length())
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int x =0;
        if(s[i]!='0')
        {
            x += solve(s,i+1,dp);
        }
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
        {
            x += solve(s,i+2,dp);
        }
        return dp[i]=x;
    }
    int tab(string s)
    {
        int n = s.size();
   	    vector<int> dp(n + 1, 0);
   	    dp[0] = 1;
   	    dp[1] = s[0] != '0' ? 1 : 0;	// Initialize dp[1] based on the first character

   	    for (int index = 2; index <= n; index++)
   	    {
   	       	// Single-digit case
   	        if (s[index - 1] != '0')
   	            dp[index] += dp[index - 1];

   	       	// Two-digit case
   	        int twoDigitNum = stoi(s.substr(index - 2, 2));
   	        if (twoDigitNum >= 10 && twoDigitNum <= 26)
   	            dp[index] += dp[index - 2];
   	    }

   	    return dp[n];
    }

    int numDecodings(string s) {
        int i = s.length();
        // vector<int>dp(i+1,-1);
        // return solve(s,0,dp);
        return tab(s);
    }
};






