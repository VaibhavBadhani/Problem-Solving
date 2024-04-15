// class Solution {
// public:
// void bfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int &time){
//     int m = grid.size(),n= grid[0].size();
//     queue<pair<int,int>>q;
//     for(int k = 0;k<m;k++){
//             for(int l =0;l<n;l++){
//                 if(grid[k][l]==2){
//                     vis[k][l]=true;
//                     q.push({k,l});
//                 }
//             }
//         }
//         if(q.empty()){
//             time =1;
//             return;
//         }
//         while(!q.empty()){
//             int k = q.size();
//             time++;
//             while(k--){
//                 pair<int,int>fnode = q.front();
//                 q.pop();
//                 int x = fnode.first;
//                 int y = fnode.second;
//                 grid[x][y] = 2;
//                 int dx[]={-1,0,1,0};
//                 int dy[]={0,1,0,-1};
//                 for(int i = 0;i<4;i++){
//                     int newx = x+dx[i];
//                     int newy = y+dy[i];
//                     if(newx>=0&&newy>=0&&newx<grid.size()&&newy<grid[0].size()&&!vis[newx][newy]&&grid[newx][newy]==1){
//                         q.push({newx,newy});
//                         vis[newx][newy]=true;
//                     }
//                 }
//             }
//         }
// }

//     int orangesRotting(vector<vector<int>>& grid) {
//         int time = 0;
//         vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
//         bfs(grid,vis,time);
//         int m = grid.size(),n= grid[0].size();
//         for(int i =0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1) return -1;
//             }
//         }
//         return time-1;
//     }
// };






// not using visited matrix space


class Solution {
public:
void bfs(vector<vector<int>>&grid,int &time){
    int m = grid.size(),n= grid[0].size();
    queue<pair<int,int>>q;
    for(int k = 0;k<m;k++){
            for(int l =0;l<n;l++){
                if(grid[k][l]==2){
                    // vis[k][l]=true;
                    q.push({k,l});
                }
            }
        }
        if(q.empty()){
            time =1;
            return;
        }
        while(!q.empty()){
            int k = q.size();
            time++;
            while(k--){
                pair<int,int>fnode = q.front();
                q.pop();
                int x = fnode.first;
                int y = fnode.second;
                grid[x][y] = 2;
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                for(int i = 0;i<4;i++){
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    if(newx>=0&&newy>=0&&newx<grid.size()&&newy<grid[0].size()&&grid[newx][newy]==1){
                        q.push({newx,newy});
                        grid[newx][newy]=0;
                    }
                }
            }
        }
}

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        // vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        bfs(grid,time);
        int m = grid.size(),n= grid[0].size();
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return time-1;
    }
};





