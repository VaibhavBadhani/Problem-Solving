class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n==1) return 0;

        vector<int> distance(n+1,1e9);
        distance[k]=0;
        distance[0]=0;

        vector<vector<pair<int,int>>> graph(n+1);

        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v= times[i][1];
            int edgeweight= times[i][2];

            graph[u].push_back(make_pair(edgeweight,v));
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();

            int distancetosource= cur.first;
            int source= cur.second;

            for(int i=0;i<graph[source].size();i++){
                int dest= graph[source][i].second;
                int edgeweight= graph[source][i].first;

                if(distance[dest] > distancetosource + edgeweight){
                    distance[dest] = distancetosource + edgeweight;
                    pq.push(make_pair(distance[dest],dest));
                }
            }
        }

        for(int i=0;i<distance.size();i++){
            if(distance[i]==1e9) return -1;
        }

        return *max_element(distance.begin(),distance.end());
    }
};