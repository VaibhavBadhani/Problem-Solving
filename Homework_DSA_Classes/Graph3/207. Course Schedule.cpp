class Solution {
public:
    bool topoSortBfs(int numCourses,unordered_map<int,list<int>> &adjList) {
        vector<int>ans;
        queue<int> q;
        int n = numCourses;
        unordered_map<int, int> indegree;
        for (auto i : adjList)
        {
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }
        for (int i = 0; i < n; i++) 
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty()) 
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for (auto nbr : adjList[frontNode]) 
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                q.push(nbr);
                }
            }
        }
        if(ans.size()==n) return true;
        return false;
  }
   bool dfs(int i ,unordered_map<int,list<int>> &adjlist,vector<int> &vis,vector<int>&path){
       vis[i]=1;
       path[i]=1;
       for(auto it:adjlist[i]){
           if(!vis[it]){
               if(dfs(it,adjlist,vis,path)) return true;
           }
           else if(path[it]==1) return true;
       }
       path[i]=0;
       return false;

   }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjlist;
        for(auto it: prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adjlist[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adjlist,vis,path)) return false;
            }
        }
        return true;
        // bool ans = topoSortBfs(numCourses,adjlist);
        // return ans;
    }
};