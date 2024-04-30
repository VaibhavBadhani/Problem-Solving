class DSU {
    public:
    vector<int> parent, rank;
   
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1,0);
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        void Union(int x, int y) {
            int u = find(x);
            int v = find(y);
            if (u == v) return ;
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } 
            else if (rank[v] < rank[u]) {
                parent[v] = u;
            } 
            else {
                parent[u] = v;
                rank[v]++;
            }
            return ;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU graph(n);
        vector<int> result;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (graph.find(u)==graph.find(v)) {
                result.push_back(u);
                result.push_back(v);
            }
            else{
                graph.Union(u,v);
            }
        }

        return result;
    }
};
