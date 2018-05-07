#include "linkedListmod.h"

class Solution {
    int NodeSize(ListNode*root){
        int cnt=0;
        while(root!=NULL){
            cnt++;
            root=root->next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=NodeSize(root);
        int split_size=len/k;
        int mod=len%k;
        vector<ListNode*>ret;
        ret.resize(k);
        for(int a=0; a<k; a++){
            ret[a]=root;
            int size=split_size+(mod-->0?1:0);
            if(size>0){
                while(--size){
                    root=root->next;
                }
                ListNode*temp=root;
                root=root->next;
                temp->next=NULL;
            } 
        }
    return ret;
    }
};