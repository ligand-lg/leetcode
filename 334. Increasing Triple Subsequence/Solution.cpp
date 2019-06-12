//
// Created by fry on 2019-05-31
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool increasingTriplet(const vector<int> &nums) {
    int m1 = INT_MAX, m2 = INT_MAX;
    for (auto x : nums) {
      if (x <= m1) {
        m1 = x;
      } else if (x <= m2) {
        m2 = x;
      } else {
        return true;
      }
    }
    return false;
  }
};
