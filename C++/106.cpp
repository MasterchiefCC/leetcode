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
        
		vector<bool>used(inorder.size(), false);
		int p_index = postorder.size() - 1;
        
		return constr_tree(inorder, postorder, used, p_index, 0, inorder.size());
	}
private:
	TreeNode * constr_tree(const vector<int>& inorder, const vector<int>& postorder, vector<bool>& used, int &p_index, int start, int end) {
		if (p_index<0)return NULL;

		const int& cur = postorder[p_index];
		int mid = start;
		while (mid<inorder.size() && inorder[mid] != cur)++mid;
		if (mid >= used.size() || used[mid] == true)return NULL;

		used[mid] = true;
		TreeNode*root = new TreeNode(cur);
		--p_index;

		root->right = constr_tree(inorder, postorder, used, p_index, mid + 1, end);
		root->left = constr_tree(inorder, postorder, used, p_index, start, mid);

		return root;
	}
};