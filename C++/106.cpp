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
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return NULL;
        
		int p_index = postorder.size() - 1;
        
		return constr_tree(inorder, postorder, p_index, 0, inorder.size());
	}
private:
	TreeNode * constr_tree(const vector<int>& inorder, const vector<int>& postorder, int &p_index, int start, int end) {
        if(start==end)return NULL;
		if (p_index<0)return NULL;

		const int& cur = postorder[p_index];
		int mid = start;
		while (mid<inorder.size() && inorder[mid] != cur)++mid;

		TreeNode*root = new TreeNode(cur);
		--p_index;

		root->right = constr_tree(inorder, postorder, p_index, mid + 1, end);
		root->left = constr_tree(inorder, postorder, p_index, start, mid);

		return root;
	}
};