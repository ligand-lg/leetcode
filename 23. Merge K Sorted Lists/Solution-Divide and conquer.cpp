//
// Created by fry on 2019-05-20
//

/**
 * 利用 分治 来合并 (也就是归并排序）
 * T(n) = O(nlogk)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode dummy(0);
    ListNode *p = &dummy;
    while (left != nullptr || right != nullptr) {
      if ((left != nullptr) && (right == nullptr || left->val <= right->val)) {
        p->next = left;
        left = left->next;
      }else {
        p->next = right;
        right = right->next;
      }
      p = p->next;
    }
    p->next = nullptr;
    return dummy.next;
  }

  ListNode *mergeSort(const vector<ListNode *> &lists, int begin, int end) {
    if (begin >= end)
      return nullptr;
    if (end - begin == 1)
      return lists[begin];

    int mid = (begin + end) / 2;
    ListNode *left = mergeSort(lists, begin, mid);
    ListNode *right = mergeSort(lists, mid, end);
    return merge(left, right);
  }

 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    return mergeSort(lists, 0, lists.size());
  }
};
