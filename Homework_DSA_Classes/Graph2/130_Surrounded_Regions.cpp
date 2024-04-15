class Solution {
public:
void dfs(int x ,int y ,vector<vector<int>>& vis,vector<vector<char>> &mat,vector<int>& dx,vector<int> 
    &dy){
        vis[x][y]=1;
        
        for(int i =0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0&&newy>=0&&newx<mat.size()&&newy<mat[0].size()&&!vis[newx][newy]&&mat[newx][newy]=='O'){
                dfs(newx,newy,vis,mat,dx,dy);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dx ={-1,0,1,0};
        vector<int >dy = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&mat[0][j]=='O'){
                dfs(0,j,vis,mat,dx,dy);
            }
            if(!vis[n-1][j]&&mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat,dx,dy);
            }
        }
        for(int i =0;i<n;i++){
            if(!vis[i][0]&&mat[i][0]=='O'){
                dfs(i,0,vis,mat,dx,dy);
            }
            if(!vis[i][m-1]&&mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,dx,dy);
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j]&&mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        
    }
};