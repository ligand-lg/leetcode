//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <string>

using namespace std;

class Solution {
 public:
  int titleToNumber(string s) {
    int res = 0;
    for (auto c: s)
      res = res * 26 + (c - 'A' + 1);
    return res;
  }
};
