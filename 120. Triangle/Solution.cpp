/**
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int minimumTotal(const vector<vector<int>> &triangle) {
    if (triangle.empty())
      return 0;
    int rows = triangle.size();
    // 首尾无限大，为了兼容
    vector<int> res(rows + 1, INT_MAX);
    res[1] = triangle[0][0];
    for (int row = 2; row <= rows; ++row) {
      for (int col = row; col > 0; --col) {
        res[col] = min(res[col - 1], res[col]) + triangle[row - 1][col - 1];
      }
    }
    return *min_element(res.begin(), res.end());
  }
};
