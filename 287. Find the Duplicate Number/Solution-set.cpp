//
// Created by fry on 2019-05-26
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    unordered_set<int> tmp;
    for (auto n : nums) {
      if (tmp.find(n) != tmp.end())
        return n;
      tmp.insert(n);
    }
    return -1;
  }
};
