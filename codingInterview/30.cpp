#include "../leetcode.h"
/*
 * f(n) 以第 n 位为结尾的子序列的和最大值。
 * 转移方程: f(n) = f(n-1) > 0 ? f(n-1) + n : n,  n >= 1;
 * 初始值:   f(0) = 0;
 * 
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.size() == 0) throw "error";
    int result = array[0];
    int max_width_end_n_1 = -1;
    for (auto n : array) {
      if (max_width_end_n_1 > 0)
        max_width_end_n_1 = max_width_end_n_1 + n;
      else
        max_width_end_n_1 = n;
      result = max(max_width_end_n_1, result);
    }
    return result;
  }
};