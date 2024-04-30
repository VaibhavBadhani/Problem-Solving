class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n+1);
        DisjointSet bob(n+1);
        int c = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0]==3){
                if(alice.findUPar(u)!=alice.findUPar(v)){
                    alice.unionByRank(u,v);
                }
                if(bob.findUPar(u)!=bob.findUPar(v)){
                    bob.unionByRank(u,v);
                }
                else c++;
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                int u = edges[i][1];
                int v = edges[i][2];
                if(alice.findUPar(u)!=alice.findUPar(v)){
                    alice.unionByRank(u,v);
                }
                else{
                    c++;
                }
            }
            else if(edges[i][0]==2){
                int u = edges[i][1];
                int v = edges[i][2];
                if(bob.findUPar(u)!=bob.findUPar(v)){
                    bob.unionByRank(u,v);
                }
                else{
                    c++;
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(alice.findUPar(i) != alice.findUPar(n)  || bob.findUPar(i) != bob.findUPar(n) ){
                return -1;
            }
        }
        return c;

    }
};