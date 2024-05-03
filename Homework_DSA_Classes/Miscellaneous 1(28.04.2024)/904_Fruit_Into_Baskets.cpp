class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i =0;
        int j =0;
        unordered_map<int,int>mp;
        int ans = INT_MIN;
        while(j<f.size()){
            mp[f[j]]++;
            while(mp.size()>2){
                mp[f[i]]--;
                if(mp[f[i]]==0)mp.erase(f[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};