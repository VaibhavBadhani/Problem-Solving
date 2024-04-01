class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void inorder(Node* root,map<int,int>&mp,vector<int>&v){
        if(!root) return;
        inorder(root->left,mp,v);
        if(mp.find(root->data)!=mp.end()){
            v.push_back(root->data);
        }
        else{
            mp[root->data]++;
        }
        inorder(root->right,mp,v);
        return;
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
      vector<int>v;
      if(!root1&&!root2) return v;
      map<int,int>mp;
      inorder(root1,mp,v);
      inorder(root2,mp,v);
       return v;
    }
   
};