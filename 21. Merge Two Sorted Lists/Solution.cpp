//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(m+n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy_head(0);
    ListNode *p1 = l1, *p2 = l2, *q = &dummy_head;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val < p2->val) {
        q->next = p1;
        p1 = p1->next;
      } else {
        q->next = p2;
        p2 = p2->next;
      }
      q = q->next;
    }
    if (p1 != nullptr)
      q->next = p1;
    if (p2 != nullptr)
      q->next = p2;
    return dummy_head.next;
  }
};
