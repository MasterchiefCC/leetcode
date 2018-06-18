#include "mod.h"
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
    int upp;
    int helper(int temp){
        int up=upp;
        upp=(temp+up)/10;
        return (temp+up)%10;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ret=new ListNode(0);
        ListNode*ret1=ret;
        upp=0;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL){
                ret->val=helper(l2->val);
                l2=l2->next;
            }
            else if(l2==NULL){
                ret->val=helper(l1->val);
                l1=l1->next;
            }
            else {
                ret->val=helper(l1->val+l2->val);
                l1=l1->next;
                l2=l2->next;
            }
            if(l1==NULL&&l2==NULL)break;
            ret ->next=new ListNode(0);
            ret=ret->next;
        }
        if(upp==1){ret->next=new ListNode(1);return ret1;}
        return ret1;
    }
};
