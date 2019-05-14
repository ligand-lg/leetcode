//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int climbStairs(int n) {
    int a = 1, b = 2, tmp;

    if (n <= 1)
      return 1;

    for (int i = 2; i < n; i++) {
      tmp = a + b;
      a = b;
      b = tmp;
    }
    return b;

  }
};
