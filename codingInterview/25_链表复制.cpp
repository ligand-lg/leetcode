#include "../leetcode.h"

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
      if (pHead == nullptr) 
        return nullptr;
      map<RandomListNode *, RandomListNode *> old2new;
      old2new[nullptr] = nullptr;
      for (auto p = pHead; p != nullptr; p = p->next) {
        old2new[p] = new RandomListNode(p->label);
      }
      RandomListNode *new_head = old2new[pHead];
      auto p = new_head;
      for(auto q = pHead; q != nullptr; p = p->next, q = q->next) {
        p->next = old2new[q->next];
        p->random = old2new[q->random];
      }
      return new_head;
    }
};