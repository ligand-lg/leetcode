/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return nullptr;
    auto dumpy_head = new ListNode(0);
    ListNode *p = dumpy_head, *q = head;
    while (q && q->next) {
      if (q->val != q->next->val) {
        p->next = q;
        p = q;
        q = q->next;
      } else {
        int val = q->val;
        while (q && q->val == val)
          q = q->next;
      }
    }
    p->next = q;
    return dumpy_head->next;
  }
};
