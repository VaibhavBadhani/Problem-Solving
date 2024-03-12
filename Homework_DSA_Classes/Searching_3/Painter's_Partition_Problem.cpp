

bool isposs(int mid,vector<int> &b,int k ){
    int c = 1;
    int boardsum =0;
    for(int i =0;i<b.size();i++){
        if(b[i]>mid) {return false;}
        if(boardsum+b[i]>mid){
            c++;
            if(c>k) return false;
            boardsum = b[i];
        }
        else{
            boardsum+=b[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int low =0;
    int high = 1e8;
    int ans = -1;
    while(low<=high){
        int mid  =  low+(high-low)/2;
        if(isposs(mid,boards,k)==true){
            ans = mid;
            high = mid-1;
        }
        else{
            low  = mid+1;
        }
    }
    return ans;
}