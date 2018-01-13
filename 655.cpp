#include "treemod.h"

class Solution {
    int findDepth(TreeNode*root){
        if(root==NULL)return 0;
        else return max(findDepth(root->left), findDepth(root->right))+1;
    }
    void helper(TreeNode*root, int left, int right, vector<vector<string>>&buffer, int cur_depth){
        if(root==NULL)return;
        int mid=(left+right)/2;
        buffer[cur_depth][mid]=to_string(root->val);
        helper(root->left, left, mid, buffer, cur_depth+1);
        helper(root->right, mid, right, buffer, cur_depth+1);
        return;
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {  
        int depth=findDepth(root);
        int len=(1<<depth)-1;
        vector<vector<string>>ret(depth, vector<string>(len, ""));
        helper(root, 0, len, ret, 0);
        return ret;
    }
};
