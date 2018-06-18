#include "mod.h"
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ret;
        vector<int>cur;
        dfs(root, cur, ret, 0, sum);
        return ret;
    }
private:
    void dfs(TreeNode*root, vector<int>& cur, vector<vector<int>>& ret, int sum, const int& target){
        if(root==NULL)return;
        sum+=root->val;
        cur.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==target){
            ret.push_back(cur);
            cur.pop_back();
        }
        else{
            dfs(root->left, cur, ret, sum, target);
            dfs(root->right, cur, ret, sum, target);
            cur.pop_back();
        }
    }
};