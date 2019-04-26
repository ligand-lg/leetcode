//
// Created by ligand on 2019-04-26.
//

#include "../leetcode.h"

class Solution {
 public:
  vector<int> maxInWindows(const vector<int> &a, unsigned int k) {
    vector<int> res;
    deque<int> s;
    for (unsigned int i = 0; i < a.size(); ++i) {
      while (s.size() && a[s.back()] <= a[i]) s.pop_back();
      while (s.size() && i - s.front() + 1 > k) s.pop_front();
      s.push_back(i);
      if (k && i + 1 >= k) res.push_back(a[s.front()]);
    }
    return res;
  }
};
