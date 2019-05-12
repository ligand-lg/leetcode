//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode *new_head = reverseList(head->next);
    head->next = nullptr;

    if (new_head != nullptr) {
      ListNode *p = new_head;
      while (p->next != nullptr)
        p = p->next;
      p->next = head;
    } else {
      new_head = head;
    }

    return new_head;
  }
};
