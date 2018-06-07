#include"mod.h"
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
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())return NULL;
		int pre_idx = 0;
		TreeNode*root = constr_tree(preorder, inorder, pre_idx, 0, preorder.size());
		return root;
	}
private:
	TreeNode * constr_tree(const vector<int>& preorder, const vector<int>& inorder, int& pre_idx, int in_left, int in_right) {
		if (in_left == in_right)return NULL;
		if (pre_idx >= preorder.size())return NULL;
		
		int cur = in_left;
		while (cur < in_right&&inorder[cur] != preorder[pre_idx]) {
			++cur;
		}
		TreeNode*root = new TreeNode(inorder[cur]);
		++pre_idx;
		root->left = constr_tree(preorder, inorder,pre_idx, in_left, cur);
		root->right = constr_tree(preorder, inorder,  pre_idx, cur + 1, in_right);
		return root;
	}
};