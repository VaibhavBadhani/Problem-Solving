class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int,long long>> dq;
        long long sum = 0;
        int ans = INT_MAX;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum >= k){
                ans = min(ans,i+1);
            }
            while(dq.size() and sum - dq.front().second >= k){
                ans = min(ans,i - dq.front().first);
                dq.pop_front();
            }
            while(dq.size() and dq.back().second >= sum){
                dq.pop_back();
            }
            dq.push_back({i,sum});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};




// int i =0;
//         int j =0;
//         int ans  = INT_MAX;
//         int sum =0;
//         while(i<nums.size()){
//             sum+=nums[i];
//             cout<<i<<"="<<sum<<" ";
//             while(j<=i&&sum>=k){
//                 ans= min(ans,i-j+1);

//                 cout<<i<<"="<<sum<<" o "<<i-j+1;
//                 sum-=nums[j++];
//             }
//             i++;

//         }
//         return ans==INT_MAX?-1:ans;