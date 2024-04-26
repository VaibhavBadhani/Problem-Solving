class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(auto it:flights){
            g[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int steps = i.first;
            int node = i.second.first;
            int dis = i.second.second;
            if(steps>k) continue;
            for(auto itr:g[node]){
                int adjnode = itr.first;
                int adjdis = itr.second;
                if(dis+adjdis<dist[adjnode]){
                    dist[adjnode]= dis+adjdis;
                    q.push({steps+1,{adjnode,adjdis+dis}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};