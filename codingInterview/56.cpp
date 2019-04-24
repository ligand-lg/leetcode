//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
 public:
  ListNode *deleteDuplication(ListNode *pHead) {
    ListNode fake_head(0);
    ListNode *cur_old = pHead;
    ListNode *cur_new = &fake_head;
    while (cur_old != nullptr) {
      int val = cur_old->val;
      ListNode *p;
      for (p = cur_old; p->next != nullptr && p->next->val == val; p = p->next);
      if (cur_old == p) {
        cur_new->next = cur_old;
        cur_new = cur_new->next;
        cur_old = cur_old->next;
      } else {
        // delete
        ListNode *free_start = cur_old;
        ListNode *free_end = p->next;

        cur_old = p->next;

        p = nullptr;
        ListNode *f;
        while (free_start != free_end) {
          f = free_start;
          free_start = free_start->next;
          delete f;
        }
        f = nullptr;
      }
    }
    cur_new->next = nullptr;
    return fake_head.next;
  }
};
