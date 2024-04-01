/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , int targetSum,   vector <int>& path, vector<vector<int>>& ans,int sum)
    {
          //base case
          if(root==NULL)return ; 
          //leaf
          if(!root->left&&!root->right)
          {
              
              sum+=root->val;
              if(sum==targetSum)
              {
                  path.push_back(root->val);
                  ans.push_back(path);
                  path.pop_back();
              }
              sum-=root->val;
              return ;
          }
          //inc exl
          path.push_back(root->val);
          solve(root->left,targetSum,path,ans,sum+root->val);
          solve(root->right,targetSum,path,ans,sum+root->val);
          path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
       vector <int> path;
       int sum =0;
       solve(root,targetSum,path,ans,sum);
       return ans;
    }
};






