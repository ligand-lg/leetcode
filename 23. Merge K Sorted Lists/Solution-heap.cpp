//
// Created by fry on 2019-05-20
//

/**
 * 使用堆来优化每次比较
 * T(n) = O(nlogk)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  typedef struct {
    bool operator()(const ListNode *lhs, const ListNode *rhs) const {
      return lhs->val > rhs->val;
    }
  } cmp;
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> max_heap;
    ListNode dummy(0);
    ListNode *p = &dummy;

    for (auto l : lists) {
      if (l != nullptr)
        max_heap.push(l);
    }

    while (!max_heap.empty()) {
      ListNode *next_node = max_heap.top();
      max_heap.pop();
      p->next = next_node;
      p = p->next;
      if (next_node->next != nullptr)
        max_heap.push(next_node->next);
    }

    p->next = nullptr;
    return dummy.next;
  }
};
