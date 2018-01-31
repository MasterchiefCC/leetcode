/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "treemod.h"
class Solution {
    int ret;
    void helper(TreeNode*root, const int &k, int &cur){
       if(root==NULL||k==cur)return;
       helper(root->left, k, cur);
       ++cur;
       if(cur==k){
           ret=root->val;
           return;
       }
       helper(root->right, k, cur);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int temp=0;
        helper(root, k, temp);
        return ret;
    }
};