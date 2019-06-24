/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    ListNode less_dumpy_head(0), greater_dumpy_head(0);
    ListNode *less_p = &less_dumpy_head, *greater_p = &greater_dumpy_head;
    while (head != nullptr) {
      if (head->val < x) {
        less_p->next = head;
        less_p = less_p->next;
      } else {
        greater_p->next = head;
        greater_p = greater_p->next;
      }
      head = head->next;
    }
    greater_p->next = nullptr;
    less_p->next = greater_dumpy_head.next;
    return less_dumpy_head.next;
  }
};
