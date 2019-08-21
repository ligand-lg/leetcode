#include "../leetcode.h"

class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
      ListNode *new_head = nullptr;
      while(head != nullptr) {
        auto p = head;
        head = head->next;
        p->next = new_head;
        new_head = p;
      }
      return new_head;
    }
};