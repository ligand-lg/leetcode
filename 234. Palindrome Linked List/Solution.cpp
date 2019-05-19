//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    stack<int> tmp;
    for (ListNode *p = head; p != nullptr; p = p->next)
      tmp.push(p->val);
    ListNode *p = head;
    while (!tmp.empty()) {
      if (tmp.top() != p->val)
        return false;
      tmp.pop();
      p = p->next;
    }
    return true;
  }
};
