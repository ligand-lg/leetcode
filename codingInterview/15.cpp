#include "../leetcode.h"

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
      if (pHead == nullptr) return nullptr;
      ListNode *p = pHead->next;
      ListNode *q = pHead;
      ListNode *p_next;
      q->next = nullptr;
      while (p != nullptr) {
        p_next = p->next;
        p->next = q;
        q = p;
        p = p_next;
      }
      return q;
    }
};