#include "leetcode.h"

/*
 * 转移方程: f(n) = f(i-1) * f(n-i), i = [1...n], n > 0
 * 初始值:   f(0) = 1, f(1) = 1
 *
 * T(n) = O(n^2)
 * S(n) = O(n);
 */

class Solution {
  vector<int> dp;
  int helper(int n) {
    // 没有初始化
    if (dp[n] < 0) {
      int result = 0;
      // 跟节点
      for (int i = 1; i <= n; ++i) {
        result += helper(i-1) * helper(n - i);
      }
      dp[n] = result;
    }
    return dp[n];
  }

 public:
  int numTrees(int n) {
    if (n < 1) return 0;
    dp = vector<int>(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return helper(n);
  }
};

int main() {
  Solution s;
  cout << s.numTrees(3);
}
