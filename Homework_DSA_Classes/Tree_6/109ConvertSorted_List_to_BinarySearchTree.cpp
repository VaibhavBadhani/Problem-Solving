/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>& nums,int i ,int j){
        if(i>j){
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[(i+(j-i)/2)]);
        root->left = solve(nums,i,(i+(j-i)/2)-1);
        root->right = solve(nums,(i+(j-i)/2)+1,j);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int n = nums.size();
        return solve(nums,0,n-1);
        
    }
};