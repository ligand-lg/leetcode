//
// Created by ligand on 2019-04-22.
//
#include "../leetcode.h"
class Solution {
 public:
  ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    int len1, len2;
    len1 = len2 = 0;
    for (auto p = pHead1; p != nullptr; p = p->next) len1++;
    for (auto p = pHead2; p != nullptr; p = p->next) len2++;
    auto p = pHead1;
    auto q = pHead2;
    while (len1 > len2) {
      p = p->next;
      len1--;
    }
    while (len2 > len1) {
      q = q->next;
      len2--;
    }
    while (p != q) {
      p = p->next;
      q = q->next;
    }
    return p;
  }
};
