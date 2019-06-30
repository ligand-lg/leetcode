/**
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);
    for (int row = 2; row <= rowIndex; ++row) {
      for (int i = row - 1; i > 0; --i) {
        res[i] += res[i - 1];
      }
    }
    return res;
  }
};

