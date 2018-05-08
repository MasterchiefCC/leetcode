/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null)return head;
        ListNode cur=head, ret=cur.next, last=null;
        while(cur!=null&&cur.next!=null){
            ListNode temp=cur.next.next, exchange=cur.next;
            cur.next.next=cur;
            cur.next=temp;
            if(last!=null)last.next=exchange;
            last=cur;
            cur=cur.next;
        }
        return ret;
    }
}