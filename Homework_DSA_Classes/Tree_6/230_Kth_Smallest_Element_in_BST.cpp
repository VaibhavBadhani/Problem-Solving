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
    void ino(TreeNode* root, vector<int>& in){
        if(!root) return;
        ino(root->left,in);
        in.push_back(root->val);
        ino(root->right,in);
    }
    int kthSmallest(TreeNode* root, int &k) {
        vector<int>in;
        ino(root,in);
        return in[k-1];
    }
};

public:
    int ans =-1;
    int a = 0;
    void inorder(TreeNode* root){
        if(root != NULL && a>0){
            inorder(root->left );
            a--;
            if(a==0){
                ans=root->val;
                return;
            }
            inorder(root->right );
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        a=k;
        inorder(root);
        return ans;
    }