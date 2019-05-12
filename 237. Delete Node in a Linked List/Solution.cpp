//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  void deleteNode(ListNode *node) {
    ListNode *p = node;
    for (; p->next->next != nullptr; p = p->next)
      p->val = p->next->val;
    p->val = p->next->val;
    p->next = nullptr;
  }
};
