//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
 public:
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    set<ListNode *> data;
    for (ListNode *p = pHead; p != nullptr; p = p->next) {
      if (data.find(p) != data.end())
        return p;
      data.insert(p);
    }
    return nullptr;
  }
};
