//
// Created by fry on 2019-05-16
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> res(digits);

    int i = digits.size() - 1;
    int carry = 1;
    while (carry != 0 && i >= 0) {
      res[i] = (digits[i] + carry) % 10;
      carry = (digits[i] + carry) / 10;
      i--;
    }
    if (carry > 0)
      res.insert(res.begin(), carry);

    return res;
  }
};
