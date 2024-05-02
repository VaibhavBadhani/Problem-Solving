class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int i =0;
        int j = 0;
        int sum =0;
        if(k==n) return accumulate(cp.begin(),cp.end(),0);
        sum =accumulate(cp.begin(),cp.end(),0);
        int temp =0;
        while(i<(n-k)){
            temp += cp[i++];
        }
        
        cout<<temp<<endl;
        int ans =0;
        ans = max(ans,sum-temp);
        while(i<n){
            temp+=cp[i++];
            temp-=cp[j++];
            ans= max(ans,sum-temp);
        }
        return ans;
    }
};