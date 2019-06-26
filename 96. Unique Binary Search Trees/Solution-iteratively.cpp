/**
 * 转移方程: f(n) = Sum(f(i-1), f(n-i)), i = [1...n]
 * 初始值:   f(0) = 1, f(1) = 1
 *
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  static vector<int> dp;
 public:
  int numTrees(int n) {
    int size = dp.size();
    if (size <= n) {
      dp.resize(n + 1, 0);
      for (int x = size; x <= n; ++x) {
        int cnt = 0;
        for (int i = 1; i <= x; ++i) {
          cnt += dp[i - 1] * dp[x - i];
        }
        dp[x] = cnt;
      }
    }
    return dp[n];
  }
};

vector<int> Solution::dp{1, 1};
