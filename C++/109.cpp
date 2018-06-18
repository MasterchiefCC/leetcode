#include "mod.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>buffer;
        ListNode*temp=head;
        while(temp!=NULL){
            buffer.push_back(temp->val);
            temp=temp->next;
        }
		TreeNode*ret = NULL;
		if (buffer.empty())return ret;
		vector<bool>used(buffer.size(), false);
		ret = build_tree(buffer, used, 0, buffer.size());
		return ret;

	}
private:
	TreeNode * build_tree(const vector<int>& buffer, vector<bool>& used, int left, int right) {
		int mid = left + (right - left) / 2;
		if (used[mid])return NULL;
		TreeNode* root = new TreeNode(buffer[mid]);
		used[mid] = true;

		root->left = build_tree(buffer, used, left, mid);
		root->right = build_tree(buffer, used, mid, right);
		return root;
	}
};