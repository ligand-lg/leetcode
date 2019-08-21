#include "../leetcode.h"

class Solution {
  double _power(double bas, unsigned int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return bas;
    double half = _power(bas, exp/2);
    return half * half * (exp%2 == 0?1:bas);
  }
public:
    double Power(double bas, int exp) {
      return exp < 0 ? 1/_power(bas, -exp) : _power(bas, exp);
    }
};