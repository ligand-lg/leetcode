/**
 *
 * T(n) = O(?)
 * S(n) = O(1)
 */

class Solution {
 public:
  // 牛顿法开方.
  int mySqrt(int x) {
    double result = 1.0;
    double diff = 1.0;
    while (diff > 0.0001 || diff < -0.0001) {
      diff = (result * result - x) / (2 * result);
      result -= diff;
    }
    return int(result);
  }
};