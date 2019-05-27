//
// Created by fry on 2019-05-27
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int next(int n) {
    int res = 0;
    while (n != 0) {
      res += (n % 10) * (n % 10);
      n /= 10;
    }
    return res;
  }
 public:
  bool isHappy(int n) {
    int fast = n, slow = n;
    do {
      slow = next(slow);
      fast = next(next(fast));
      if (fast == 1)
        return true;
    } while (fast != slow);
    return false;
  }
};
