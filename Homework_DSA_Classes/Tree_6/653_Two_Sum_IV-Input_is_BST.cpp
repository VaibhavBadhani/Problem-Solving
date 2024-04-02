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
  void stoe(TreeNode* root,vector<int> &inor)
  {
      if(root==NULL)return ;
      stoe(root->left,inor);
      inor.push_back(root->val);
      stoe(root->right,inor);

  }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inor;
        stoe(root,inor);
        int s =0;
        int  e = inor.size()-1;
        while(s<e)
        {
            int sum = inor[s]+inor[e];
            if(sum==k)return true;
            else if(sum<k)s++;
            else
            e--;
        }
        return false;
    }
};