//
// Created by ligand on 2019-05-13.
//
/**
 * T(n) = O(?)
 * S(n) = O(1)
 *
 */

class Solution {
 public:
  int getSum(int a, int b) {
    int c = 0;
    while (b != 0) {
      c = (((a & b) & 0xffffffff) << 1);
      a ^= b;
      b = c;
    }
    return a;
  }
};
