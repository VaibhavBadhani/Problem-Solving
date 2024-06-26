class DSU{
	public:
	vector<int> arr;
	DSU(int n)
	{
		arr.assign(n,0);
		for(int i=0;i<n;i++)
		{
			arr[i]=i;
		}
	}
	int find(int x)
	{
		if(x==arr[x])
		{
            return x;
			
		}
		return arr[x]=find(arr[x]);
	}
	void merge(int a, int b)
	{
		int x=find(a);
		int y=find(b);
		arr[x]=y;
	}
};
class Solution {
public:
	int minSwapsCouples(vector<int>& row) {

		int n=row.size();
		 DSU* dsu=new DSU(n);
		 for(int i=1;i<n;i+=2)
		 {
			 dsu->merge(i,i-1);
		 }

		for(int i=1;i<n;i+=2)
		{
			dsu->merge(row[i],row[i-1]);
		}
		unordered_map<int,int> m;

		for(int i=0;i<n;i++)
		{
			int cur=dsu->find(i);
			m[cur]++;
		}

		int ans=0;
		for(auto& x:m)
		{
			ans+=x.second/2-1;
		}
		return ans;
	}
};