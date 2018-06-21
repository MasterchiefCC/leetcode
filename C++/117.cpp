#include "mod.h"
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)return;

		TreeLinkNode*cur = root, *nxtLevel = NULL, *pre = NULL;

		while (cur) {
			if (cur->left)helper(cur->left, nxtLevel, pre);
			if (cur->right)helper(cur->right, nxtLevel, pre);
			cur = cur->next;
			if (cur == NULL) {
				cur = nxtLevel;
				pre = NULL;
				nxtLevel = NULL;
			}
		}
	}
private:
	inline void helper(TreeLinkNode* child, TreeLinkNode*& nxtLevel, TreeLinkNode*& pre) {
		if (nxtLevel == NULL)nxtLevel = child;
		else if (pre == NULL) {
			nxtLevel->next = child;
			pre = child;
		}
		else {
			pre->next = child;
			pre = child;
		}
	}
};