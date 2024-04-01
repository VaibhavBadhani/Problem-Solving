if(!root) return vector<int>{};
        map<int,int> mp;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        mp[0]=root->data;
        while(!q.empty()){
            auto ff = q.front();q.pop();
            int x = ff.second.first;
            int y = ff.second.second;
            Node* nd = ff.first;
            if(mp.find(x)==mp.end()){
                mp[x] = nd->data;
            }
            if(nd->left){
                q.push({nd->left,{x-1,y+1}});
            }
            if(nd->right){
                q.push({nd->right,{x+1,y+1}});
            }
        }
        vector<int>p;
        for(auto a :mp){
            p.push_back(a.second);
        }
        return p;
    
    }
