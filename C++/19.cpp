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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        return helper(head, cnt, n);
    }
private:
    ListNode* helper(ListNode*cur, int& cnt, int n){
        if(cur->next==NULL){
            ++cnt;
            if(n==1){
                delete cur;
                return NULL;
            }
            return cur;
        }
        cur->next=helper(cur->next, cnt, n);
        if(++cnt==n){
            ListNode*temp=cur->next;
            delete cur;
            return temp;
        }
        return cur;
    }
};