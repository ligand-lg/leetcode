//
// Created by ligand on 2019-05-14.
//

/**
 * 转移方程: f(x,y) = f(x-1, y) + f(x, y-1);
 * 初始值:   f(0, 0) = 1;
 * T(n) = O(m*n)
 * O(n) = O(1)
 */

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[100][100];
    memset(dp, 0, sizeof(int) * 100 * 100);

    // init
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0)
          // up to down
          dp[i][j] += dp[i - 1][j];
        if (j > 0)
          // left to right
          dp[i][j] += dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};
