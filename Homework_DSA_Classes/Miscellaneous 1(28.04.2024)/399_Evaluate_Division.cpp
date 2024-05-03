class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>>& mp,map<string,int>&vis,string start,string end){
        if(start==end) return 1; 
        vis[start]=1;
        for(auto it:mp[start]){
            if(vis.find(it.first)==vis.end()){
                double val = it.second*dfs(mp,vis,it.first,end);
                if(val>0) return val;
            }   
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qu) {
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i =0;i<eq.size();i++){
            mp[eq[i][0]].push_back({eq[i][1],val[i]});
            mp[eq[i][1]].push_back({eq[i][0],1.0/val[i]});
        }
        vector<double>ans;
        for(int i =0;i<qu.size();i++){
            if(mp.find(qu[i][0])==mp.end()||mp.find(qu[i][1])==mp.end()){
                ans.push_back(-1.0);
            }
            else{
                map<string,int>vis;
                ans.push_back(dfs(mp,vis,qu[i][0],qu[i][1]));
            }
        }
        return ans;

    }
};