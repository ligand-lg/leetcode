#include "../leetcode.h"
/*
 * DP: 
 * f(n) 以第 n 位为结尾的子序列的和最大值。
 * 转移方程: f(k) = a_k + max(f(k-1), 0);
 * 初始值:   f(0) = 0;
 * 
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
public:
    int FindGreatestSumOfSubArray(const vector<int> &array) {
      int prev = 0;
      int ans = array[0];
      for(auto item : array) {
        prev = item + max(prev, 0);
        ans = max(prev, ans);
      }
      return ans;
    }
};

/**
 * 分治：
 * 最大值为以下三种的中的最大值：
 *  1. [start, mid) 左边的最大值
 *  2. [mid+1, end) 右边的最大值
 *  3. 包含 mid 的最大值
 * T(n) = O(nlogn)
 * S(n) = O(1)
 */
class Solution2 {
  int help(const vector<int> &array, int start, int end) {
    if (start >= end)
      return INT_MIN;
    int mid = (start + end) / 2;
    // 包含 mid 的 max
    int right_ans = array[mid];
    int tmp = 0;
    for (int i = mid; i < end; ++i) {
      tmp += array[i];
      right_ans = max(right_ans, tmp);
    }
    int left_ans = array[mid];
    tmp = 0;
    for (int i = mid; i >= start; --i) {
      tmp += array[i];
      left_ans = max(left_ans, tmp);
    }
    return max(max(help(array, start, mid), help(array, mid+1, end)), left_ans + right_ans - array[mid]);
  }
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
      return help(array, 0, array.size());
    }
};