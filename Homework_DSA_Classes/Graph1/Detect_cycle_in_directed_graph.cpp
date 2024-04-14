 bool dfs(int i,vector<int>& vis,vector<int>& path,vector<int> adj[]){
        vis[i]= 1;
        path[i]=1;
        for(int a:adj[i]){
            if(!vis[a]){
                if(dfs(a,vis,path,adj)) return true;
            }
            else if(path[a]==1){
                return true;
            }
        }
        path[i]=0;
        return false;
    }
 bool isCyclic(int v, vector<int> adj[]) {
        // vector<int> indegre(v);
        // for(int i =0;i<v;i++){
        //     for(int a:adj[i]){
        //         indegre[a]++;
        //     }
        // }
        // queue<int>q;
        // for(int a=0;a<indegre.size();a++){
        //     if(indegre[a]==0){
        //         q.push(a);
        //     }
        // }
        // int cnt =0;
        // while(!q.empty()){
        //     int node = q.front();
        //     cnt++;
        //     q.pop();
        //     for(int a:adj[node]){
        //         indegre[a]--;
        //         if(indegre[a]==0){
        //             q.push(a);
        //         }
        //     }
        // }
        
        // return cnt!=v?true:false;
        vector<int>vis(v);
       vector<int>path(v);
       for(int i =0;i<v;i++){
           if(!vis[i]){
               if(dfs(i,vis,path,adj)) return true;
           }
       }
       return false;
    }