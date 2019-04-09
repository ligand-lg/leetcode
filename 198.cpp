#include "leetcode.h"

/* 
 * 转移方程: f(n) = max(f(n-1), f(n-2) + a[n])
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int rob(vector<int>& nums) {
    int count = nums.size();
    int f_n_1, f_n_2, result;
    f_n_1 = 0;
    f_n_2 = 0;
    result = 0;
    for (int i = 0; i < count; i++) {
      result = max(f_n_1, f_n_2 + nums[i]);
      f_n_2 = f_n_1;
      f_n_1 = result;
    }
    return result;
  }
};