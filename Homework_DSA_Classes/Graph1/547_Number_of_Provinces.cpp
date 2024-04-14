class Solution {
public:
    void dfs(unordered_map<int,bool>&vis,vector<vector<int>>& c,int i ){
        vis[i]=true;
        int size = c[i].size();
        for(int col =0;col<size;col++){
            if(c[i][col]&&!vis[col]){
                    dfs(vis,c,col);  
            }
        }
    }
    void bfs(unordered_map<int,bool>&vis,vector<vector<int>>& c,int i){
        queue<int>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            i = q.front();
            q.pop();
            int size = c[i].size();
            for(int col=0;col<size;col++){
                if(c[i][col]&&!vis[col]){
                    q.push(col);
                    vis[col]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        unordered_map<int,bool>vis;
        int n = c.size();
        int count =0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(vis,c,i);
                
            }
        }
        return count;
    }
};
