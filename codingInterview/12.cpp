#include "../leetcode.h"

class Solution {
  double helper(double base, unsigned int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    // 偶数
    double result;
    if (exponent % 2 == 0) {
      result = helper(base, exponent / 2);
      return result * result;
    } else {
      result = helper(base, (exponent - 1) / 2);
      return result * result * base;
    }
  }

 public:
  double Power(double base, int exponent) {
    if (exponent == 0 && base == 0) return 0;
    if (exponent == 0) return 1;
    unsigned int exp = (unsigned int)(exponent > 0 ? exponent : 0 - exponent);
    double result = helper(base, exp);
    if (exponent < 0) result = 1 / result;
    return result;
  }
};
