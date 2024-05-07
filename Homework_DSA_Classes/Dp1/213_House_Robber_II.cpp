// class Solution {
// public:
//     int solve(vector<int>& nums,int i ,int n,vector<int>&dp)
//     {
//         if(i>n) return 0;
//         if(i==n)return nums[i];
//         if(dp[i]!=-1)return dp[i];
//         int inc = nums[i]+solve(nums,i+2,n,dp);
//         int exe = solve(nums,i+1,n,dp);
//         dp[i]=max(inc,exe);
//         return dp[i]; 
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)
//             return nums[0];
//         vector<int>dp1(nums.size()+1,-1);
//         vector<int>dp2(nums.size()+1,-1);
//         int res2 = solve(nums,1,nums.size()-1,dp1);
//         int res1 = solve(nums,0,nums.size()-2,dp2);
        
//         return max(res1,res2);
//     }
// };


class Solution {
public:
    int solve(vector<int>& nums,int i ,int n,vector<int>&dp)
    {
        if(i>n) return 0;
        if(i==n)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int inc = nums[i]+solve(nums,i+2,n,dp);
        int exe = solve(nums,i+1,n,dp);
        dp[i]=max(inc,exe);
        return dp[i]; 
    }
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
        if(nums.size()==1)
            return nums[0];
        // vector<int>dp1(nums.size()+1,-1);
        // vector<int>dp2(nums.size()+1,-1);

        // int res2 = solve(nums,1,nums.size()-1,dp1);
        // int res1 = solve(nums,0,nums.size()-2,dp2);
        vector<int> v1 ;
        v1.assign(nums.begin(), nums.end()-1);  
        vector<int> v ;
        v.assign(nums.begin()+1, nums.end());  
        int res1 = tabulation(v1);
        int res2 = tabulation(v);
        return max(res1,res2);
    }
};