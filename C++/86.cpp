#include "mod.h"
class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		ListNode*ret = NULL, *part = NULL, *cur = head, *last = NULL;
		while (cur != NULL) {
			if (cur->val<x&&ret == NULL) {
				ret = cur;
				if (head != ret) {
					ListNode*temp = head;
					while (temp->next != ret)temp = temp->next;
					temp->next = ret->next;
					ret->next = head;
				}
			}
			else if (cur->val<x&&last->val >= x) {
				last->next = cur->next;
				cur->next = part->next;
				part->next = cur;
				part = cur;
				cur = last;
			}
			if (cur->val<x)part = cur;
			last = cur;
			cur = cur->next;
		}
		if (ret == NULL)return head;
		return ret;
	}
};