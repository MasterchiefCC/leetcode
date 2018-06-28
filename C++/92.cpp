#include "mod.h"
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || m == n) return head;
    int cnt = 1;
    ListNode* dummy = new ListNode(INT_MAX);
    dummy->next = head;
    ListNode* start = dummy;
    while (cnt != m) {
      start = start->next;
      ++cnt;
    }

    start->next = reverse(start->next, n - m + 1);

    ListNode* ret = start == dummy ? start->next : head;

    delete dummy;

    return ret;
  }

 private:
  inline ListNode* reverse(ListNode* cur, int cnt) {
    ListNode *pre = NULL, *head = cur;
    while (cnt > 0) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
      --cnt;
    }
    head->next = cur;
    return pre;
  }
};
