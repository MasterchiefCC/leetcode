#include "treemod.h"
class Solution {
  vector<int>result;
  void helper(TreeNode*root){
    if(root==NULL)return;
    result.push_back(root->val);
    helper(root->left);
    helper(root->right);
  }
public:
    vector<int> preorderTraversal(TreeNode* root) {
      result.clear();
      helper(root);
      return result;
    }
};