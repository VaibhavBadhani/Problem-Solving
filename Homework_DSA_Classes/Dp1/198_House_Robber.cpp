class Solution {
public:
   int rec(vector<int>& nums,int n ,int i,vector<int>& dp)
   {
       if(i>n)
       {
           return 0;
       }
       if(i==n)
       {
           return nums[i];
       }
       if(dp[i]!=-1)return dp[i];
       int include a nums[i]+rec(nums,n,i+2,dp);
       int ex = 0+rec(nums,n,i+1,dp);
       return dp[i]=max(include,ex);

   }
    int rob(vector<int>& nums) {

        int n = nums.size()-1;
        vector<int>dp(nums.size(),-1);
        int ans = rec(nums,n,0,dp);
        return ans;
    }
};



class Solution {
public:
//    int rec(vector<int>& nums,int n ,int i,vector<int>& dp)
//    {
//        if(i>n)
//        {
//            return 0;
//        }
//        if(i==n)
//        {
//            return nums[i];
//        }
//        if(dp[i]!=-1)return dp[i];
//        int include a nums[i]+rec(nums,n,i+2,dp);
//        int ex = 0+rec(nums,n,i+1,dp);
//        return dp[i]=max(include,ex);
//    }
   int tabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        // int n = nums.size()-1;
        // vector<int>dp(nums.size(),-1);
        // int ans = rec(nums,n,0,dp);
        // return ans;
        return tabulation(nums);
    }
};








//previous attempts






// int solvebyrecursion(vector<int>& nums,int n,vector<int>& dp)
//     {
//         if(n<0) return 0;
//         if(n==0) return nums[0];
//         if(dp[n]!=-1) return dp[n];
//         int include = nums[n]+solvebyrecursion(nums,n-2,dp);
//         int exclude = 0+solvebyrecursion(nums,n-1,dp);
//         dp[n]= max(include,exclude);
//         return dp[n];
//     }
//     int solvebytabulation(vector<int>&nums,int n )
//     {
//         vector<int>dp(n+1,0);
//         dp[0]=nums[0];
//         for(int i =1;i<=n;i++)
//         {
//             int temp=0;
//             if(i-2>=0) {temp = dp[i-2];}
//             int include = nums[i]+temp;
//             int exclude = 0+dp[i-1];
//             dp[i]= max(include,exclude);
//         }
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         // int n = nums.size()-1;
//         //  vector <int> dp(n+1,-1); 
//         // return solvebyrecursion(nums,n,dp);
//         int n = nums.size()-1;
//         return solvebytabulation(nums,n);
//     }

// class Solution {
// public:
//     int solve(vector<int>& nums,int i,vector<int>& dp)
//     {
//         if(i>nums.size()-1) return 0;
//         if(i==nums.size()-1) return nums[nums.size()-1];
//         if(dp[i]!=-1) return dp[i];

//         int inc = nums[i]+solve(nums,i+2,dp);
//         int exe = 0+solve(nums,i+1,dp);
//         dp[i] =max(inc,exe);
//         return dp[i];

//     }
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size(),-1);
//         return solve(nums,0,dp);
//     }
// };












// int solvebyrecursion(vector<int>& nums,int n,vector<int>& dp)
//     {
//         if(n<0) return 0;
//         if(n==0) return nums[0];
//         if(dp[n]!=-1) return dp[n];
//         int include = nums[n]+solvebyrecursion(nums,n-2,dp);
//         int exclude = 0+solvebyrecursion(nums,n-1,dp);
//         dp[n]= max(include,exclude);
//         return dp[n];
//     }
//     int solvebytabulation(vector<int>&nums,int n )
//     {
//         vector<int>dp(n+1,0);
//         dp[0]=nums[0];
//         for(int i =1;i<=n;i++)
//         {
//             int temp=0;
//             if(i-2>=0) {temp = dp[i-2];}
//             int include = nums[i]+temp;
//             int exclude = 0+dp[i-1];
//             dp[i]= max(include,exclude);
//         }
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         // int n = nums.size()-1;
//         //  vector <int> dp(n+1,-1); 
//         // return solvebyrecursion(nums,n,dp);
//         int n = nums.size()-1;
//         return solvebytabulation(nums,n);
//     }

// class Solution {
// public:
//     int solve(vector<int>& nums,int i,vector<int>& dp)
//     {
//         if(i>nums.size()-1) return 0;
//         if(i==nums.size()-1) return nums[nums.size()-1];
//         if(dp[i]!=-1) return dp[i];

//         int inc = nums[i]+solve(nums,i+2,dp);
//         int exe = 0+solve(nums,i+1,dp);
//         dp[i] =max(inc,exe);
//         return dp[i];

//     }
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size(),-1);
//         return solve(nums,0,dp);
//     }
// };
