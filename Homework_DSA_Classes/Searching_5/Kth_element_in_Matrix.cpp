

int up(int A[MAX],int val,int m){
    int low =0;
    int high = m-1;
    int ans = m;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid]>val){
            ans= mid;
            high = mid-1;
        }   
        else  low = mid+1;
        
    }
    return ans;
}
int bb(int A[MAX][MAX],int n,int m , int mid){
    int count =0;
    for(int i =0;i<n;i++){
        count+=up(A[i],mid,m);
    }
    return count;
}
int kthSmallest(int A[MAX][MAX], int n, int k)
{
  int low = INT_MAX;
    int high = INT_MIN;
    int m = n;
    for(int i =0;i<n;i++){
        low = min(low,A[i][0]);
        high = max(high,A[i][m-1]);
    }
    while(low<high){
        int mid = low+(high-low)/2;
        int count = bb(A,n,m,mid);
        if(count<k) low= mid+1;
        else high = mid;
    }
    return low;
}
