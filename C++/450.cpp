#include "treemod.h"
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL||root->val==key&&root->left==NULL&&root->right==NULL)return NULL;
        TreeNode*cur=root, *parent=NULL;
        
        while(cur!=NULL&&cur->val!=key){
            parent=cur;
            if(cur->val<key)cur=cur->right;
            else if(cur->val>key)cur=cur->left;
        }
        if(cur==NULL)return root;
        if(parent==NULL&&cur->left!=NULL&&cur->right==NULL){
            root=root->left;
            delete cur;
            return root;
        }
        if(parent==NULL&&cur->left==NULL&&cur->right!=NULL){
            root=root->right;
            delete cur;
            return root;
        }

        delete_helper(cur, parent);
        return root;
    }
    
private:
    void delete_helper(TreeNode*cur, TreeNode*parent){
        bool is_left=(parent!=NULL&&parent->left==cur)?true:false;
        if(cur->left==NULL&&cur->right==NULL){
            if(is_left)parent->left=NULL;
            else parent->right=NULL;
            delete cur;
        }
        else if(cur->left!=NULL&&cur->right==NULL){
            if(is_left)parent->left=cur->left;
            else parent->right=cur->left;
            delete cur;
        }
        else if(cur->left==NULL&&cur->right!=NULL){
            if(is_left)parent->left=cur->right;
            else parent->right=cur->right;
            delete cur;
        }
        else{
            TreeNode *left_sub=cur->left, *sub_parent=cur;
            while(left_sub->right!=NULL){
                sub_parent=left_sub;
                left_sub=left_sub->right;
            }
            cur->val=left_sub->val;
            delete_helper(left_sub, sub_parent);
        }
    }
};