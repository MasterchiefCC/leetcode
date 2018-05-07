#include "mod.h"
struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> temp;
        temp.push(root);
        while(1){
            TreeNode*T=temp.front();
            if(T->right!=NULL)temp.push(T->right);
            if(T->left!=NULL)temp.push(T->left);
            if(temp.size()==1)return T->val;
            else temp.pop();
        }
    }
};