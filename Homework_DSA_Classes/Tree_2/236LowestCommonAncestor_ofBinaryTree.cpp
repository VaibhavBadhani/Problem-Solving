/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null)return null;
        //p&q check
        if(root.val==p.val)return p;
        if(root.val==q.val)return q;
        //not foun d
        TreeNode lans= lowestCommonAncestor(root.left,p,q);
        TreeNode rans= lowestCommonAncestor(root.right,p,q);
        //check
        if(lans==null&&rans==null)return null;
        if(lans!=null&&rans==null)return lans;
        if(lans==null&&rans!=null)return rans;
        else
        return root;

    }
}