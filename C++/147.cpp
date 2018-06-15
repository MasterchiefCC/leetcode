#include "mod.h"
class Solution {
public:
	ListNode * insertionSortList(ListNode* head) {
        if(head==NULL)return NULL;
		ListNode*ret = head, *cur = head->next, *last = head;

		while (cur != NULL) {
			if (last->val>cur->val) {
				if (cur->val<ret->val) {
					last->next = cur->next;
					cur->next = ret;
					ret = cur;
					cur = last->next;
				}
				else {
					ListNode*pre = ret, *back = ret->next;
					while (cur->val>back->val) {
						pre = back;
						back = back->next;
					}
					last->next = cur->next;
					cur->next = back;
					pre->next = cur;
					cur = last->next;
				}
			}
			else {
				last = cur;
				cur = cur->next;
			}
		}
		return ret;
	}
};