//
// Created by fry on 2019-05-20
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;

    n++;
    while (n > 0) {
      p = p->next;
      n--;
    }

    while (p != nullptr) {
      p = p->next;
      q = q->next;
    }

    q->next = q->next->next;

    return dummy.next;
  }
};
