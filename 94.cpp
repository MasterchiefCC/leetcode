#include "mod.h"
struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    void helper(TreeNode*root, vector<int>&buffer){
        if(root==NULL)return;
        helper(root->left, buffer);
        buffer.push_back(root->val);
        helper(root->right, buffer);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        helper(root, ret);
        return ret;
    }
};