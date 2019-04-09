#include "leetcode.h"

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode* p = head;
    ListNode* q = head;
    do {
      p = p->next;
      if (!p) return false;
      p = p->next;
      q = q->next;
    } while (p && p != q);
    return p != NULL;
  }
};