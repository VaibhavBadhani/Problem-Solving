Strongly Connected Components (Kosaraju's Algo)
void dfs1(int i ,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs1(it,vis,adj,st);
            }
        }
        st.push(i);
    }
    private:
    void dfs2(int i ,vector<int>& vis,vector<vector<int>>& adjt){
        vis[i]=1;
        for(auto it:adjt[i]){
            if(!vis[it]){
                dfs2(it,vis,adjt);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        vector<int>vis(v,0);
        stack<int>st;
        for(int i =0;i<v;i++){
            if(!vis[i]){
                dfs1(i,vis,adj,st);
            }
        }
        //transposing the graph 
        vector<vector<int>>adjt(v);
        for(int i =0;i<v;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjt[it].push_back(i);
            }
        }
        int ans =0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(!vis[x]){
                ans++;
                dfs2(x,vis,adjt);
            }
        }
        return ans;
    }