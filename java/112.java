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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        int cur=sum-root.val;
        if(cur==0&&root.left==null&&root.right==null)return true;
        else if(hasPathSum(root.left, cur))return true;
        else if(hasPathSum(root.right, cur))return true;
        else return false;
    }
}