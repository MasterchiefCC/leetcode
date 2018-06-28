#include "mod.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode*pre=NULL, *cur=head;
        while(cur->next!=NULL){
            ListNode*temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        cur->next=pre;
        return cur;
    }
};