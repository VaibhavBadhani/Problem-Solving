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
    void ino(TreeNode* root,vector<int>& in){
        if(!root) return;
        ino(root->left,in);
        in.push_back(root->val);
        ino(root->right,in);
    }
    int i =0;
    void sortbst(TreeNode* root, vector<int>&in){
        if(!root) return;
        sortbst(root->left,in);
        if(root->val!=in[i])swap(in[i],root->val);
        i++;
        sortbst(root->right,in);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        ino(root,in);
        for(int a:in){
            cout<<a<<" ";
        }
        cout<<endl;
        sort(in.begin(),in.end());
        for(int a:in){
            cout<<a<<" ";
        }
        sortbst(root,in);
    }
};