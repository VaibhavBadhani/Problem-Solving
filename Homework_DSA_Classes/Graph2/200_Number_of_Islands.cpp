class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';
        vector<int>dx = {-1,1,0,0};
        vector<int>dy = {0,0,-1,1};
        for(int k =0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0&&nj>=0&&ni<grid.size()&&nj<grid[0].size()&&grid[ni][nj]=='1'){
                dfs(ni,nj,grid);
            }
        }
    }
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto fnode = q.front();q.pop();
            int i = fnode.first;
            int j = fnode.second;
            grid[i][j]='0';
            vector<int>dx = {-1,1,0,0};
            vector<int>dy = {0,0,-1,1};
            for(int k =0;k<4;k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0&&nj>=0&&ni<grid.size()&&nj<grid[0].size()&&grid[ni][nj]=='1'){
                    q.push({ni,nj});
                }
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};