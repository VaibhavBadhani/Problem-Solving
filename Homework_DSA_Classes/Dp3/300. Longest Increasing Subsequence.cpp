class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>binary;
        binary.push_back(nums[0]);
        for(int i =1;i<nums.size();i++){
            if(nums[i]>binary.back()){
                binary.push_back(nums[i]);
            }
            else{
                int index = lower_bound(binary.begin(),binary.end(),nums[i])-binary.begin();
                binary[index]=nums[i];
            }
        }
        return binary.size();
    }
};

// class Solution {
// public:
//     int recurrsion(vector<int>& nums,int i, int prev){
//         if(i>=nums.size()) return 0;
//         int take =0;
//         if(prev==-1||nums[i]>nums[prev]){
//             take =1+recurrsion(nums,i+1,i);
//         }
//         int nottake = 0+recurrsion(nums,i+1,prev);
//         return max(take,nottake);
//     }
//     int memoisation(vector<int>& nums,int i, int prev,vector<vector<int>>&dp){
//         if(i>=nums.size()) return 0;
//         int take =0;
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
//         if(prev==-1||nums[i]>nums[prev]){
//             take =1+memoisation(nums,i+1,i,dp);
//         }
//         int nottake = 0+memoisation(nums,i+1,prev,dp);
//         return dp[i][prev+1]=max(take,nottake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int i =0;
//         int prev = -1;
//         int n =  nums.size();
//         vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,0));
//         for(i=n-1;i>=0;i--){
//             for(prev =i-1;prev >=-1;prev--){
//                 int take =0;
//                 if(prev==-1||nums[i]>nums[prev]){
//                     take =1+dp[i+1][i+1];
//                 }
//                 int nottake = dp[i+1][prev+1];
//                 dp[i][prev+1]=max(take,nottake);
//             }
//         }
//         return dp[0][0];
//     }
// };




