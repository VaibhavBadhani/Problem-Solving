 bool isCyclic(int v, vector<int> adj[]) {
        vector<int> indegre(v);
        for(int i =0;i<v;i++){
            for(int a:adj[i]){
                indegre[a]++;
            }
        }
        queue<int>q;
        for(int a=0;a<indegre.size();a++){
            if(indegre[a]==0){
                q.push(a);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(int a:adj[node]){
                indegre[a]--;
                if(indegre[a]==0){
                    q.push(a);
                }
            }
        }
        
        return cnt!=v?true:false;
    }