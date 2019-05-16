//
// Created by fry on 2019-05-16
//
/**
 * 转移方程: f(n) = max(f(n-1), f(n-2) + a[n])
 * 初始值:   f(1) = 1, f(0) = 1
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int rob(vector<int> &nums) {
    int res_n_1, res_n_2, res;
    res = res_n_1 = res_n_2 = 0;

    for (auto n:nums) {
      res = max(res_n_1, res_n_2 + n);
      res_n_2 = res_n_1;
      res_n_1 = res;
    }

    return res;
  }
};
