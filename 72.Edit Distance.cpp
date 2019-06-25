#include "leetcode.h"

/**
 * 转移方程: f(n1, n2) = min(f(n1-1, n2-1) + not_same(w1[n1-1], w2[n2-1]),
 *           f(n1, n2-1) + 1, f(n1-1, n2) +1);
 * 初始值:    f(0, n2) = n2, f(n1, 0) = n1;
 *
 * T(n) = O(n1*n2);
 * S(n) = O(n1*n2);
 */

class Solution {
  vector<vector<int>> dp;
  string w1;
  string w2;
  int helper(int n1, int n2) {
    if (n1 <= 0) return n2;
    if (n2 <= 0) return n1;
    // 没有缓存，计算。
    int i1 = n1 - 1, i2 = n2 - 1;
    if (dp[i1][i2] < 0) {
      int result = min(helper(n1, n2 - 1), helper(n1 - 1, n2)) + 1;
      result = min(result, helper(n1 - 1, n2 - 1) + (w1[i1] == w2[i2] ? 0 : 1));
      dp[i1][i2] = result;
    }
    return dp[i1][i2];
  }

 public:
  int minDistance(string word1, string word2) {
    w1 = word1;
    w2 = word2;
    // -1表示没有初始化
    dp = vector<vector<int>>(w1.length(), vector<int>(w2.length(), -1));
    return helper(w1.length(), w2.length());
  }
};

int main() {
  Solution s;
  cout << s.minDistance("intention", "execution");
  return 0;
}
