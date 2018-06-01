#include "treemod.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)return false;
        int cur=sum-root->val;
        if(cur==0&&root->left==NULL&&root->right==NULL)return true;
        else if(hasPathSum(root->left, cur))return true;
        else if(hasPathSum(root->right, cur))return true;
        else return false;
    }

};