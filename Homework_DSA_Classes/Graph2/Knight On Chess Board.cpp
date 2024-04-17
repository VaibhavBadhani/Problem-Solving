
int Solution::knight(int n, int m, int x, int y, int p, int r) {
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    int dx[8]={-2,-1,1,2,-2,-1,1,2};
    int dy[8]={-1,-2,-2,-1,1,2,2,1};
    x--; y--; p--; r--;
    queue<pair<int,int>>q;
    q.push({x,y});
    dist[x][y]=0;
    vis[x][y]=1;
    while(!q.empty()) {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i==p && j==r)  return dist[i][j];
        for(int k=0; k<8; k++) {
            int nwi=i+dx[k];
            int nwj=j+dy[k];
            if(nwi>=0 && nwi<n && nwj>=0 && nwj<m && vis[nwi][nwj]==0) {
                dist[nwi][nwj]=1+dist[i][j];
                vis[nwi][nwj]=1;
                q.push({nwi,nwj});
            }
        }
    }
    return -1;
}
