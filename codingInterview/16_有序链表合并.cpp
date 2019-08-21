#include "../leetcode.h"

class Solution {
public:
    ListNode* Merge(ListNode* h1, ListNode* h2) {
      ListNode dummpy_head_node(0);
      ListNode *dummpy_head = &dummpy_head_node;
      auto p = dummpy_head;
      while(h1 != nullptr && h2 != nullptr) {
        if (h1->val < h2->val) {
          p->next = h1;
          h1 = h1->next;
        }else{
          p->next = h2;
          h2 = h2->next;
        }
        p = p->next;
      }
      if (h1 != nullptr) p->next = h1;
      if (h2 != nullptr) p->next = h2;
      return dummpy_head->next;
    }
};