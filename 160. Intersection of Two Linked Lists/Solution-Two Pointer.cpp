//
// Created by fry on 2019-05-21
//

/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    bool resetP = true, resetQ = true;

    while (p != q) {

      if (p == nullptr) {
        if (resetP) {
          p = headB;
          resetP = false;
        }
      } else {
        p = p->next;
      }

      if (q == nullptr) {
        if (resetQ) {
          q = headA;
          resetQ = false;
        }
      } else {
        q = q->next;
      }
    }

    return p;
  }
};
