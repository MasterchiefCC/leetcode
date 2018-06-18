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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ret;
        map<string, int>cnt;
        helper(root, cnt, ret);
        return ret;
    }
private:
    string helper(TreeNode*root, map<string, int> &cnt, vector<TreeNode*> &ret){
        if(root==NULL)return "#";
        string cur=to_string(root->val)+","+helper(root->left, cnt, ret)+","+helper(root->right, cnt, ret);
        if(++cnt[cur]==2)ret.push_back(root);
        return cur;
    }
};