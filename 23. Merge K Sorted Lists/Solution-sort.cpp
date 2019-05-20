//
// Created by fry on 2019-05-20
//

/**
 * 直接对所有节点排序
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> data;

    for (auto p : lists) {
      while (p != nullptr) {
        data.push_back(p);
        p = p->next;
      }
    }

    // sort
    sort(data.begin(), data.end(), [](const auto &a, const auto &b) -> bool {
      return a->val < b->val;
    });

    ListNode dummy(0);
    ListNode *p = &dummy;
    for (auto node : data) {
      p->next = node;
      p = p->next;
    }
    p->next = nullptr;

    return dummy.next;
  }
};
