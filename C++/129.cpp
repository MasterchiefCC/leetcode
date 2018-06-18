#include"treemod.h"

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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
private:
    int helper(TreeNode* root, int cur){
        if(root==NULL)return cur;
        if(root->left==NULL&&root->right==NULL)return cur*10+root->val;
        
        int left=root->left!=NULL?helper(root->left, cur*10+root->val):0;
        int right=root->right!=NULL?helper(root->right, cur*10+root->val):0;
        return left+right;
    }
};