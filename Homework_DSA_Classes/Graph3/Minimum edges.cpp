class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<vector<pair<int,int>>> adj(n+1);
            for(int i=0;i<edges.size();i++){
               // cout << "edges[" << i << "][0]: " << edges[i][0] << ", edges[" << i << "][1]: " << edges[i][1] << endl; // Print edges[i][0] and edges[i][1]
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            int inf = 100000;
            vector<int>d(n+1,inf);
            d[src]=0;
            deque<int>q;
            q.push_front(src);
            while(!q.empty()){
                int v = q.front();
                q.pop_front();
                for(auto ed:adj[v]){
                    int u = ed.first;
                    int w = ed.second;
                    if(d[v]+w<d[u]){
                        d[u]= d[v]+w;
                        if(w==1) q.push_back(u);
                        else q.push_front(u);
                    }
                    
                }
            }
            
            return d[dst]==inf?-1:d[dst];
        }
};