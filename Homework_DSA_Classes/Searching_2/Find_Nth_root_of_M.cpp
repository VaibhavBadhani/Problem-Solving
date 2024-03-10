Find Nth root of M

	public:
	int functions(int mid,int n ,int m){
	    long long ans =1;
	    for(int i =1;i<=n;i++){
	        ans=ans*mid;
	        if(ans>m) return 2;
	    }
	    if(ans==m) return 0;
	    return 1;
	}
	int NthRoot(int n, int m)
	{
	    int l = 1;
	    int h = m;
	    while(l<=h){
	        int mid = (l+h)/2;
	        if(functions(mid,n,m)==0){
	            return mid;
	        }
	        else if(functions(mid,n,m)==1){
	            l = mid+1;
	        }
	        else{
	            h= mid-1;
	        }
	    }
	    return -1;
	}  