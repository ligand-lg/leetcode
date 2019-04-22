//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
    if (data.size() < 2) return;
    int a_xor_b = 0;
    for (auto d:data) {
      a_xor_b = a_xor_b ^ d;
    }
    int firstOneBit = 0;
    while ((a_xor_b & 1) == 0) {
      a_xor_b >>= 1;
      firstOneBit++;
    }

    int a, b;
    a = b = 0;
    for (auto d: data) {
      int s = d >> firstOneBit;
      if ((s & 1) == 1) {
        a ^= d;
      }else {
        b ^= d;
      }
    }
    *num1 = a;
    *num2 = b;
  }
};
