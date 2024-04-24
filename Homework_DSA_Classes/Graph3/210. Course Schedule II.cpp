class Solution {
public:
    vector<int> topoSortBfs(int numCourses,unordered_map<int,list<int>> &adjList) {
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
        if(ans.size()==n) return ans;
        return {};
  }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,list<int>> adjlist;
        for(auto it: prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adjlist[v].push_back(u);
        }
        vector<int> ans = topoSortBfs(numCourses,adjlist);
        return ans;
    }
};