class Solution {
public:
 
    void solve(int i,int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        cout<<endl;
        cout<<m<<" "<<n<<endl;
        if(i == n-1 && j == m-1) { 
            grid[i][j]=0;
             return;
        }
        
        if(grid[i][j]==1){
            cout<<1<<" ";
            grid[i][j]=0;
            //left
            if(j-1>=0&&grid[i][j-1]!=0&&(grid[i][j-1]==4||grid[i][j-1]==6||grid[i][j-1]==1)){
                // grid[i][j-1]=0;
                solve(i,j-1,grid);
            }
            //right
            if(j+1<m&&grid[i][j+1]!=0&&(grid[i][j+1]==3||grid[i][j+1]==5||grid[i][j+1]==1)){
                // grid[i][j+1]=0;
                solve(i,j+1,grid);
            }
        }
        else if(grid[i][j]==2){
            cout<<2<<" ";
            grid[i][j]=0;
            //up
            if(i-1>=0&&grid[i-1][j]!=0&&(grid[i-1][j]==4||grid[i-1][j]==3||grid[i-1][j]==2)){
                // grid[i-1][j]=0;
                solve(i-1,j,grid);
            }
            //down
            if(i+1<n&&grid[i+1][j]!=0&&(grid[i+1][j]==5||grid[i+1][j]==6||grid[i+1][j]==2)){
                // grid[i+1][j]=0;
                solve(i+1,j,grid);
            }
            
        }
        else if(grid[i][j]==3){
             //left
             cout<<3<<" ";
             grid[i][j]=0;
            if(j-1>=0&&grid[i][j-1]!=0&&(grid[i][j-1]==4||grid[i][j-1]==6||grid[i][j-1]==1)){
                // grid[i][j-1]=0;
                solve(i,j-1,grid);
            }
            //down
            if(i+1<n&&grid[i+1][j]!=0&&(grid[i+1][j]==5||grid[i+1][j]==6||grid[i+1][j]==2)){
                // grid[i+1][j]=0;
                solve(i+1,j,grid);
            }
        }
        else if(grid[i][j]==4){
            //right
            cout<<4<<" ";
            grid[i][j]=0;
            if(j+1<m&&grid[i][j+1]!=0&&(grid[i][j+1]==3||grid[i][j+1]==5||grid[i][j+1]==1)){
                // grid[i][j+1]=0;
                solve(i,j+1,grid);
            }
            //down
            if(i+1<n&&grid[i+1][j]!=0&&(grid[i+1][j]==5||grid[i+1][j]==6||grid[i+1][j]==2)){
                // grid[i+1][j]=0;
                solve(i+1,j,grid);
            }
            
        }
        else if(grid[i][j]==5){
            cout<<5<<" ";
            grid[i][j]=0;
            //left
            if(j-1>=0&&grid[i][j-1]!=0&&(grid[i][j-1]==4||grid[i][j-1]==6||grid[i][j-1]==1)){
                //grid[i][j-1]=0;
                solve(i,j-1,grid);
            }
            //up
            if(i-1>=0&&grid[i-1][j]!=0&&(grid[i-1][j]==4||grid[i-1][j]==3||grid[i-1][j]==2)){
                //grid[i-1][j]=0;
                solve(i-1,j,grid);
            }
        }
        else if(grid[i][j]==6){
            cout<<6<<" ";
            grid[i][j]=0;
            //right
            if(j+1<m&&grid[i][j+1]!=0&&(grid[i][j+1]==3||grid[i][j+1]==5||grid[i][j+1]==1)){
                //grid[i][j+1]=0;
                solve(i,j+1,grid);
            }
            //up
            if(i-1>=0&&grid[i-1][j]!=0&&(grid[i-1][j]==4||grid[i-1][j]==3||grid[i-1][j]==2)){
                //grid[i-1][j]=0;
                solve(i-1,j,grid);
            }
        }
        return ;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        solve(0,0,grid);
        cout<<endl;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return grid[n-1][m-1]==0?true:false;
    }
};