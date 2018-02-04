class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        ListNode*p=head->next, *odd=head, *even=head->next, *evenHead=head->next;
        int cnt=2;
        if(p==NULL)return head;
        while(1){
            p=p->next;
            ++cnt;
            if(p==NULL)break;
            if(cnt%2==1){
                odd->next=p;
                odd=odd->next;
            }
            else{
                even->next=p;
                even=even->next;
            }
        }
        odd->next=evenHead;
        even->next=NULL;
        return head;   
    }
};
