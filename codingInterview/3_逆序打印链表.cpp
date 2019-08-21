#include "leetcode.h"

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      stack<int> tmp;
      for (auto p = head; p != nullptr; p = p->next) {
        tmp.push(p->val);
      }
      vector<int> res;
      while(!tmp.empty()) {
        res.push_back(tmp.top());
        tmp.pop();
      }
      return res;
    }
};