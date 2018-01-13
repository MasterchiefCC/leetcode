#include "treemod.h"
class Solution {
  void helper(TreeNode* root, const int &v, int cur_depth, const int &depth){
    if(root==NULL)return;
    helper(root->left, v, cur_depth+1, depth);
    helper(root->right, v, cur_depth+1, depth);
    if(cur_depth==depth){
      TreeNode*temp_left=new TreeNode(v);
      temp_left->left=root->left;
      root->left=temp_left;
      TreeNode*temp_right=new TreeNode(v);
      temp_right->right=root->right;
      root->right=temp_right;
    }
  }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
          TreeNode*temp=new TreeNode(v);
          temp->left=root;
          return temp;
        }
      helper(root, v, 1, d-1);
      return root;
    }
};