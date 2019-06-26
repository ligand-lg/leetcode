/**
 * 转移方程: f(n) = Sum(f(i-1), f(n-i)), i = [1...n]
 * 初始值:   f(0) = 1, f(1) = 1
 *
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int aux(int n, int *dp) {
    if (dp[n] != 0)
      return dp[n];
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res += aux(i - 1, dp) * aux(n - i, dp);
    }
    dp[n] = res;
    return res;
  }
 public:
  int numTrees(int n) {
    if (n < 2) return 1;
    auto dp = new int[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;
    int res = aux(n, dp);
    delete[]dp;
    return res;
  }
};
