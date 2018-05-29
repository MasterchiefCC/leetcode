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
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->left);
        flatten(root->right);
        if((root->left==NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL))return;
        else if(root->left!=NULL&&root->right==NULL){
            root->right=root->left;
            root->left=NULL;
            return;
        }
        else{
            TreeNode*temp=root->left, *cur=root->left;
            root->left=NULL;
            while(cur->right!=NULL)cur=cur->right;
            cur->right=root->right;
            root->right=temp;
        }
    }
};