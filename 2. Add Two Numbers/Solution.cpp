//
// Created by ligand on 2019-05-11.
//

/**
 * 按位相加得考虑进位
 * T(n) = O(n)
 * S(n) = O(n)
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr || l2 == nullptr)
      return nullptr;
    ListNode fake_head(0);

    ListNode *p = l1, *q = l2, *r = &fake_head;
    int a, b, carry, sum;
    carry = 0;
    while (p != nullptr || q != nullptr) {
      a = b = 0;
      if (p != nullptr)
        a = p->val;
      if (q != nullptr)
        b = q->val;
      sum = a + b + carry;
      r->next = new ListNode(sum % 10);
      carry = sum / 10;

      r = r->next;
      if (p != nullptr) p = p->next;
      if (q != nullptr) q = q->next;
    }
    // 考虑最终的一个进位
    if (carry == 1) {
      r->next = new ListNode(1);
    }
    return fake_head.next;
  }
};
