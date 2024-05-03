class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> high ;
        deque<int> low;
        int right;
        int left=0;
        int longest =0;
        for(right=0;right<nums.size();right++){
            while(!high.empty()&&(nums[high.back()]<nums[right])){
                high.pop_back();
            }
            high.push_back(right);
            while(!low.empty()&&(nums[low.back()]>nums[right])){
                low.pop_back();
            }
            low.push_back(right);
            while(!high.empty()&&!low.empty()){
                int diff = nums[high.front()]-nums[low.front()];
                if(diff>limit){
                    left = min(high.front(),low.front());
                    left++;
                    while(high.front()<left){
                        high.pop_front();
                    }
                    while(low.front()<left){
                        low.pop_front();
                    }
                }
                else{
                    break;
                }
            }
            longest= max(longest,right-left+1);
        }
        return longest;
    }
};