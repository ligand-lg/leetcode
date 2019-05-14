//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(1)
 * S(n) = O(1)
 */

#include <cstdint>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    while (n != 0) {
      res += n & 1u;
      n >>= 1;
    }
    return res;
  }
};
