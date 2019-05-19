//
// Created by fry on 2019-05-19
//

/**
 * 双指针法，一个指针每次走两步，一个指针每次走一步。如果存在环，两指针肯定会再次遇到，否则，走两步的指针会先到底
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;
    ListNode *p = head, *q = head;
    do {
      p = p->next;
      if (p == nullptr)
        return false;
      p = p->next;
      q = q->next;
    } while (p != nullptr && p != q);
    return p != nullptr;
  }
};
