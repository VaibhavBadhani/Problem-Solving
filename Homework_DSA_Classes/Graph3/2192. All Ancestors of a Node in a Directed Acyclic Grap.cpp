class Solution {
public:
    void search(int node,vector<bool>&vis,set<int>&ans,map<int,vector<int>>& mp){
        int kk=node;
        if(mp.find(node)==mp.end()){
            ans.insert(node);
            return;
        }
        vis[node]=true;
        ans.insert(node);

        for(auto i:mp[node]){
            if(!vis[i]) search(i,vis,ans,mp);
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        for(int i =0;i<n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back({});
                continue;
            }
            vector<bool>vis(n+1,false);
            set<int>res;
            search(i,vis,res,mp);
            if(res.find(i)!=res.end()) res.erase(i);
            vector<int>temp(res.begin(),res.end());
            ans.push_back(temp);
        }
        return ans;
    }
};