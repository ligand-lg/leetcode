#include "../leetcode.h"

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if (k == 0 || pListHead == nullptr) return nullptr;

      ListNode *p1 = pListHead;
      ListNode *p2 = pListHead;
      for(unsigned int i = 1; i < k; i++) {
        p1 = p1->next;
        if (p1 == nullptr) return nullptr;
      }
      while ((p1->next) != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
      }
      return p2;    
    }
};

int main () {
  Solution s;
  ListNode test_case(12);
  cout << s.FindKthToTail(&test_case, 1)->val;
  return 0;
}