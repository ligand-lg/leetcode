//
// Created by ligand on 2019-05-15.
//

/**
 * T(n) = O(log(n))
 * S(n) = O(1)
 */

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 3)
      return n == 3 || n == 1;

    return n % 3 == 0 && isPowerOfThree(n / 3);
  }
};
