class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(h.size(),vector<int>(h[0].size(),1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r  = it.second.first;
            int c = it.second.second;
            if(r==h.size()-1&&c==h[0].size()-1)  return dist[r][c];
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i =0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0&&nr>=0&&nr<h.size()&&nc<h[0].size()){
                    int currdis = abs(h[nr][nc]-h[r][c]);
                    int maxi = max(currdis,dis);
                    if(maxi<dist[nr][nc]){
                        dist[nr][nc]= maxi;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }

                }
            }
        }
        return 0;
    }
};




// priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//         vector<vector<int>>dist(h.size(),vector<int>(h[0].size(),INT_MAX));
//         pq.push({0,{0,0}});
//         dist[0][0]=0;
//         while(!pq.empty()){
//             auto fNode = pq.top();
//             pq.pop();
//             int fnodedist = fNode.first;
//             int x = fNode.second.first;
//             int y = fNode.second.second;
            
//             if(x==h.size()-1&&y==h[0].size()-1)  return dist[x][y];
            
//             int dx[] = {-1,0,1,0};
//             int dy[] = {0,1,0,-1};
//             for(int i =0;i<4;i++){
//                 int nx = x+dx[i];
//                 int ny = y+dy[i];
//                 if(nx>=0&&ny>=0&&nx<h.size()&&ny<h[0].size()){
//                     int currdist = abs(h[nx][ny]-h[x][y]);
//                     int newmax = max(currdist,fnodedist);
//                     if(newmax<dist[nx][ny]){
//                         dist[nx][ny]= newmax;
//                         pq.push({newmax,{nx,ny}});
//                     }
//                 }
//             }
//         }
//         return 0;