#include "linkedListMod.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void helper(ListNode*head, ListNode*target, ListNode*exchange){
        while(head->next!=NULL&&head->next!=target){
            head=head->next;
        }
        if(head->next==target)head->next=exchange;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*ret=head->next, *cur=head, *last=NULL;
        
        while(cur!=NULL&&cur->next!=NULL){
            ListNode*temp=cur->next->next,*exchange=cur->next;
            cur->next->next=cur;
            cur->next=temp;
            if(last!=NULL)last->next=exchange;
            last=cur;
            cur=cur->next;
        }
        return ret;
    }
};
