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
    void dfs(TreeNode* root,string s, vector<string>& ans){
        if(!root){
            if(s!=""){
                return ;
            }
            else{
                ans.push_back(s);
                return;
            }
        }
        s += to_string(root->val)+"->";
        if( !root->left && !root->right ){
            s= s.substr(0,s.size()-2);
            ans.push_back(s);
        }
        if(root->left)
        dfs(root->left,s,ans);
        if(root->right)
        dfs(root->right,s,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s = "";
        dfs(root,s,ans);
        return ans;
    }
};