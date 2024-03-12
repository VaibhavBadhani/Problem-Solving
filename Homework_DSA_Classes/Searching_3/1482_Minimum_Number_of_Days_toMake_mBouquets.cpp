class Solution {
public:
    bool isposs(int mid,vector<int>& b,int m,int k){
        int count = 0;
        int ans = 0;
        for(int i =0;i<b.size();i++){
            if(mid>=b[i]){
                count++;
                if(count==k){
                    ans++;
                    count=0;
                }

                
            }
            else{
                count =0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()/k)return -1;
        int ans = -1;
        int low = 1;
        int high = 1e9;
        while(low<=high){
            
            int mid = low +(high-low)/2;
            cout<<mid<<endl;
            if(isposs(mid,bloomDay,m,k)){
                cout<<"go";
                ans = mid;
                high  = mid -1;
                
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};