/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode _dumpy_head(0);
    auto dumpy_head = &_dumpy_head;
    dumpy_head->next = head;
    // step1, 找到m节点
    int i = 1;
    auto p = head;
    auto b1_tail = dumpy_head;
    for (; i != m; ++i) {
      b1_tail = b1_tail->next;
      p = p->next;
    }
    // step2, 翻转 m 到 n 的所有节点
    auto b2_head = p, b2_tail = p;
    for (; i <= n; ++i) {
      auto p_next = p->next;
      p->next = b2_head;
      b2_head = p;
      p = p_next;
    }
    // step3，链接翻转之后的节点到原链表
    b1_tail->next = b2_head;
    b2_tail->next = p;
    return dumpy_head->next;
  }
};
