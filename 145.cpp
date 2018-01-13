#include "treemod.h"

class Solution {
    void helper(TreeNode*root, vector<int>&buffer){
        if(root==NULL)return;
        helper(root->left, buffer);
        helper(root->right, buffer);
        buffer.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ret;
        helper(root, ret);
        return ret;
    }
};