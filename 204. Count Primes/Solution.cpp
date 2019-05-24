//
// Created by fry on 2019-05-24
//

/**
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;

    bool *prime = new bool[n];
    memset(prime, 1, n);
    int res = 1;

    int half_n = (int) sqrt(n);

    for (int i = 3; i < n; i += 2) {
      if (prime[i]) {
        ++res;
        if (i > half_n) continue;
        for (int j = i * i; j < n; j += i) {
          prime[j] = false;
        }
      }
    }
    return res;
  }
};
