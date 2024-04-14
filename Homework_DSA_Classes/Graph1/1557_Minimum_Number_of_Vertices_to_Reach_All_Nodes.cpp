class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        for(vector<int> v:edges){
            ans[v[1]]=1;
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};