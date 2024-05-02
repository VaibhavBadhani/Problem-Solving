class Solution {
public:
    bool isposs(vector<int>& ho, vector<int>& he,int mid){
        int i =0;
        for(int a :he){
            int low = a-mid;
            int high = a+mid;
            while(i<ho.size()&&(ho[i]>=low&&ho[i]<=high)){            
                i++;
            }
            if(i==ho.size()) return true;
        }
        return false;
    }
    int findRadius(vector<int>& ho, vector<int>& he) {
        sort(ho.begin(),ho.end()); sort(he.begin(),he.end());
        int low = 0;
        int high = INT_MAX;
        int ans = INT_MAX;
        while(low<=high){
            
            int mid = (high+low)/2;
            cout<<mid<<endl;
            if(isposs(ho,he,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};