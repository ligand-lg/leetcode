//
// Created by ligand on 2019-05-14.
//

/**
 * 总共 m + n - 2 步，其中 m - 1 步向下走，剩下的 n - 1 步就向左走
 * T(n) = O(min(m,n))
 * S(n) = O(1)
 *
 */

class Solution {
  int C(int m, int n) {
    if (n > m / 2)
      n = m - n;
    long res = 1;
    for (int i = m; i > m - n; i--)
      res *= i;
    for (int i = 1; i <= n; i++)
      res /= i;
    return res;
  }
 public:
  int uniquePaths(int m, int n) {
    return C(m + n - 2, m - 1);
  }
};
