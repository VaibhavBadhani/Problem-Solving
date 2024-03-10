Aggressive Cows
class Solution {
public:
    bool ifposs(int dist,int n, int k, vector<int> &s){
        int c = 1;
        int lastposs = s[0];
        for(int i =0;i<n;i++){
            if(s[i]-lastposs>=dist){
                c++;
                lastposs = s[i];
            }
            if(c>=k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 0;
        int high = INT_MAX;
        int ans = 1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(ifposs(mid,n,k,stalls)){
                ans = mid;
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};