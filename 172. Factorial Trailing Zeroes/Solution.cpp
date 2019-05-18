//
// Created by fry on 2019-05-17
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int trailingZeroes(int n) {
    unsigned long base = 5;
    int res = 0;
    while (base <= n) {
      res += n / base;
      base *= 5;
    }
    return res;
  }
};
