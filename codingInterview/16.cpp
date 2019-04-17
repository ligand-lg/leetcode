#include "../leetcode.h"

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
      if (pHead1 == nullptr) return pHead2;
      if (pHead2 == nullptr) return pHead1;
      ListNode fake_head(0);
      ListNode *p1 = pHead1;
      ListNode *p2 = pHead2;
      ListNode *curr = &fake_head;
      while (p1 != nullptr && p2 != nullptr){
        if (p1->val <= p2->val) {
          curr->next = p1;
          p1 = p1->next;
        }else {
          curr->next = p2;
          p2 = p2->next;
        }
        curr = curr->next;
      }
      if (p1 != nullptr) curr->next = p1;
      if (p2 != nullptr) curr->next = p2;
      return fake_head.next;
    }
};