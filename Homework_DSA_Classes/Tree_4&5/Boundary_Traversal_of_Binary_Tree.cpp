/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>

void lv(TreeNode<int>* root,vector<int>&left)  
{ 
    if (!root)  return; 
    queue<TreeNode<int>*> q; 
    q.push(root); 
    while (!q.empty()) 
    {     
        int n = q.size(); 
        for(int i = 1; i <= n; i++) 
        { 
            TreeNode<int>* temp = q.front(); 
            q.pop(); 
            if (i == 1) 
                left.push_back(temp->data);
            if (temp->left != NULL) 
                q.push(temp->left); 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    } 
    return;
}  
void rv(TreeNode<int>* root, vector<int>&right) 
{ 
    if (!root)  return; 
    queue<TreeNode<int>*> q; 
    q.push(root); 
    while (!q.empty()) 
    {     
        int n = q.size(); 
        for(int i = 1; i <= n; i++) 
        { 
            TreeNode<int>* temp = q.front(); 
            q.pop(); 
            if (i == n) 
                right.push_back(temp->data);
            if (temp->left != NULL) 
                q.push(temp->left); 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    }
    return; 
}  
vector <int> bottomView(TreeNode<int>*root) {
        if(!root) return vector<int>{};
        map<int,int> mp;
        queue<pair<TreeNode<int>*,pair<int,int>>>q;
        q.push({root,{0,0}});
        mp[0]=root->data;
        while(!q.empty()){
            auto ff = q.front();q.pop();
            int x = ff.second.first;
            int y = ff.second.second;
            TreeNode<int>* nd = ff.first;
            if(mp.find(x)==mp.end()){
                mp[x] = nd->data;
            }
            else{
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
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int>left;
    vector<int>right;
	lv(root,left);
    rv(root,right);
    // left.pop_back();
    reverse(right.begin(),right.end());
    // right.pop_back();
    vector<int>bot = bottomView(root);



   map<int,int>mp;
    vector<int>ans;
   

    for(int a:left){
        if(mp.find(a)!=mp.end())
        ans.push_back(a);
        mp[a]++;
    }
    for(int a:bot){
        if(mp.find(a)!=mp.end())
        ans.push_back(a);
        mp[a]++;
    }
    for(int a:right){
        if(mp.find(a)!=mp.end())
        ans.push_back(a);
        mp[a]++;
    }
   
    // for(int x:ans){
    //     cout<<x<<" ";
    // }
    return ans;
}
