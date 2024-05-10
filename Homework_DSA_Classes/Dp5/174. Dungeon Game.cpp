class Solution {
public:
    int recursion(int i ,int j ,int n,int m,vector<vector<int>>& du){
        if(i==n&&j==m) return du[i][j]>0?1:1-du[i][j];//reching end point
        if(i>=(n+1)||j>=(m+1)) return 1e9;  // reaching out of the array 
        int down = recursion(i+1,j,n,m,du)-du[i][j];  //right jayenge lekin jha pr hai agr vp moster hai to utne ki jarurat pdegi to add krlo add krne k liye minus krdiya hai
        int right = recursion(i,j+1,n,m,du)-du[i][j];  //same dino k liye
        int val = min(down,right);  // yha pr ye dekhenge ki konsa kmhai path right ya left
        return val>0?val:1; // return krte time ye dekho agar app help health jayda hai to app 1 return kroge mtlb 
        //..kuki hm apni health ko minus kr rhe hai tooo agr health 0 ya negative hui to hm return krenge 1nhi to hm usi ko return kr denge 
    }
    int memoisation(vector<vector<int>>& dp,int i ,int j ,int n,int m,vector<vector<int>>& du){
        if(i==n&&j==m) return du[i][j]>0?1:1-du[i][j];
        if(i>=(n+1)||j>=(m+1)) return 1e9; 
        if(dp[i][j]!=-1) return dp[i][j]; 
        int down = memoisation(dp,i+1,j,n,m,du)-du[i][j];  
        int right = memoisation(dp,i,j+1,n,m,du)-du[i][j]; 
        int val = min(down,right);  
        return dp[i][j]=val>0?val:1; 
    }
    int tabulation(vector<vector<int>>& du) {
        int n = du.size();
        int m = du[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =0;i<n+1;i++) {dp[i][m]=1e9;}
        for(int j =0;j<m+1;j++) {dp[n][j]=1e9;}
        for(int i =n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(i==n-1&&j==m-1) {
                    dp[i][j]= du[i][j]>0?1:1-du[i][j];
                    continue;
                }
                int down = dp[i+1][j]-du[i][j];  
                int right = dp[i][j+1]-du[i][j]; 
                int val = min(down,right);  
                dp[i][j]=val>0?val:1; 
            }
        }
        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& du) {
        int n = du.size();
        int m = du[0].size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return tabulation(du);
    }
};






