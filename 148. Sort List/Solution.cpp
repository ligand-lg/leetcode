//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(logn)
 */

#include "../leetcode.h"

class Solution {
  ListNode *mergeSort(ListNode *head, int nums) {
    if (nums <= 1)
      return head;

    // 分左右
    int left_nums = nums / 2;
    int right_nums = nums - left_nums;
    ListNode *left_head = head, *right_head = head;
    for (int i = 0; i < left_nums; i++)
      right_head = right_head->next;

    // 排左右
    left_head = mergeSort(left_head, left_nums);
    right_head = mergeSort(right_head, right_nums);

    // 合并
    return merge(left_head, left_nums, right_head, right_nums);
  }
  ListNode *merge(ListNode *left, int left_nums, ListNode *right, int right_nums) {
    ListNode dummy(0);
    ListNode *p = &dummy;
    while (left_nums > 0 || right_nums > 0) {
      if (left_nums > 0 && (right_nums <= 0 || left->val <= right->val)) {
        p->next = left;
        left = left->next;
        left_nums--;
      } else {
        p->next = right;
        right = right->next;
        right_nums--;
      }
      p = p->next;
    }
    p->next = nullptr;
    return dummy.next;
  }
 public:
  ListNode *sortList(ListNode *head) {
    int nums = 0;
    for (ListNode *p = head; p != nullptr; p = p->next)
      nums++;
    return mergeSort(head, nums);
  }
};
