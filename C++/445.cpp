/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "LinkedListMod.h"
class Solution {
    int len_cnt(ListNode*L){
        int ret=0;
        while(L!=NULL){
            ++ret;
            L=L->next;
        }
        return ret;
    }

    int helper(ListNode*L1, ListNode*L2, int size){
        if(L1==NULL)return;
        if(size){
            L1->val+=helper(L1->next, L2, size-1);
        }
        else if(L1!=NULL){
            L1->val+=L2->val+helper(L1->next, L2->next, size);
        }
        if(L1->val>=10){
            L1->val%=10;
            return 1;
        }
        else return 0;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_L1=len_cnt(l1);
        int len_L2=len_cnt(l2);
        
        int up=0;
        ListNode*ret;

        if(len_L1>=len_L2){
            ret=l1;
            up=helper(l1, l2, len_L1-len_L2);  
        }
        else {
            ret=l2;
            up=helper(l2, l1, len_L2-len_L1);
        }

        if(up){
            ListNode*temp=new ListNode(1);
            temp->next=ret;
            return temp;
        }
        return ret;
    }
};