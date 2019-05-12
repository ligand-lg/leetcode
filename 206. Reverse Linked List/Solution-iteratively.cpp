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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *new_head = head, *p = head->next, *q;
    new_head->next = nullptr;
    while (p != nullptr) {
      q = p->next;
      p->next = new_head;
      new_head = p;
      p = q;
    }

    return new_head;
  }
};
