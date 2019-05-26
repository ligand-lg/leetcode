//
// Created by fry on 2019-05-26
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *p = head, *q = head;
    do {
      if (p->next == nullptr)
        return nullptr;
      p = p->next->next;
      q = q->next;
    } while (p != nullptr & p != q);

    if (p == nullptr)
      return nullptr;

    p = head;
    while (p != q) {
      p = p->next;
      q = q->next;
    }
    return p;
  }
};
