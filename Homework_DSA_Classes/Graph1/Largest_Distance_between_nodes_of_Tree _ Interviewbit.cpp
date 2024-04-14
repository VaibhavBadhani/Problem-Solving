void dfs(int s,int par,int d,vector<int>&d1,vector<int>adj[]){
    d1[s]=d;
    for( int i=0;i<adj[s].size();i++){
        if(adj[s][i]!=par){
        dfs(adj[s][i],s,d+1,d1,adj);}
    }
}


int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>adj[n];
    vector<int>d1(n,0);
    int root;
    for( int i=0;i<n;i++){
        if(A[i]!=-1){
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
        else{
            root=i;
        }
       
       
    }
    dfs(root,-1,0,d1,adj);
    int a=max_element(d1.begin(),d1.end())-d1.begin();
    dfs(a,-1,0,d1,adj);
    int m=0;
    for( int i=0;i<n;i++){
        m=max(m,d1[i]);
    }
    return m;
}
