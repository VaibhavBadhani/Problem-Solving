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
    void helper(TreeNode* root, vector< vector< int>>& result)
    {
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            while(n--){
                TreeNode* temp = q.front();
                 v.push_back(temp->val);
                 if(temp->left!=NULL){
                     q.push(temp->left);
                 }
                 if(temp->right)
                 { 
                     q.push(temp->right);
                 }
                 q.pop();
            }
            result.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> result;
     if(root==NULL)return result;
     helper(root,result);
     return result;
    }
};


