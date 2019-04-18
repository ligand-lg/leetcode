#include "../leetcode.h"

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
      map<RandomListNode*, RandomListNode*> old_to_new;
      RandomListNode fake_head(0);
      RandomListNode* new_cur = &fake_head;
      for (auto cur = pHead; cur != nullptr; cur = cur->next) {
        new_cur->next = new RandomListNode(cur->label);
        new_cur = new_cur->next;
        old_to_new[cur] = new_cur;
      }
      new_cur = fake_head.next;
      for (auto cur = pHead; cur != nullptr; cur = cur->next) {
        new_cur->random = old_to_new[cur->random];
        new_cur = new_cur->next;
      }
      return fake_head.next; 
    }
};