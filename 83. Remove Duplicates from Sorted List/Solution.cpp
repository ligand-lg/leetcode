/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;
    ListNode *p = head, *q = head->next;
    while (q) {
      if (p->val != q->val) {
        p->next = q;
        p = q;
      }
      q = q->next;
    }
    p->next = nullptr;
    return head;
  }
};
