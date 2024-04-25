class Solution {
public:
 bool dfs(int i ,int c,int v,vector<vector<int>> adj,vector<int>&color){
        color[i]=c;
        for(auto it:adj[i]){
            
            if(color[it]==-1){
                
                if(dfs(it,!c,v,adj,color)==false)return false;
            }
            else if(color[it]==c){
                return false;
            }
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int>color(v, -1);
	    for(int i =0;i<v;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,v,adj,color)==false) return false;
	        }
	    }
	    return true;
    }
};