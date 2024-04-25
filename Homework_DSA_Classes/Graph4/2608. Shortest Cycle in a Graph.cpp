class Solution {
public:
    int mini=INT_MAX;
    void dfs(int s,int c,vector<bool>& vis,map<int,vector<int>>& mp,vector<int>& time,int par){
        vis[s]=true;
        time[s]=c;
        for(auto it:mp[s]){
            if(!vis[it]){
                dfs(it,c+1,vis,mp,time,s);
            }else if(vis[it] && it!=par){
                
                mini=min(mini,abs(time[it]-time[s])+1);
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        mini=INT_MAX;
        map<int,vector<int>> mp;    
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
                 vector<bool> vis(n,false);
                 vector<int> time(n,INT_MAX);
                dfs(i,1,vis,mp,time,-1);            
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};