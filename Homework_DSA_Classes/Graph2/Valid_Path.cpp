string dfs(int sx, int sy, int dx, int dy, vector<vector<int>>& vis) {
    vis[sx][sy] = 1;
    if (sx == dx && sy == dy) return "YES";
   
    int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
   
    for (int i = 0; i < 8; i++) {
        int nx = sx + dr[i];
        int ny = sy + dc[i];
       
        if (nx >= 0 && nx <= dx && ny >= 0 && ny <= dy && vis[nx][ny] == 0) {
            if (dfs(nx, ny, dx, dy, vis) == "YES") return "YES";
        }
    }
    return "NO";
}

string Solution::solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    vector<vector<int>> vis(x + 1, vector<int>(y + 1, 0));
    for (int i = 0; i <= x; i++) {
        int cx = i;
        for (int j = 0; j <= y; j++) {
            int cy = j;
            for (int k = 0; k < E.size(); k++) {
                int cxr = E[k];
                int cyr = F[k];
                if ((cx - cxr) * (cx - cxr) + (cy - cyr) * (cy - cyr) <= r * r) {
                    vis[cx][cy] = -1;
                }
            }
        }
    }
    if (vis[x][y] == -1) return "NO";
    return dfs(0, 0, x, y, vis);
}
