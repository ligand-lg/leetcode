//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *odd_head = head, *even_head = head->next;
    ListNode *odd = head, *even = head->next, *p = head->next->next;
    while (p != nullptr) {
      odd->next = p;
      odd = odd->next;
      p = p->next;
      if (p != nullptr) {
        even->next = p;
        even = even->next;
        p = p->next;
      }
    }

    odd->next = even_head;
    even->next = nullptr;
    return odd_head;
  }
};
