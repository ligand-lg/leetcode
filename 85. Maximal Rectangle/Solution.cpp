/**
 *
 * T(n) = O(n^3)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int maximalRectangle(const vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int cols = matrix[0].size();
    int rows = matrix.size();
    // 多一个 负一行
    auto hash_table = new int[(rows + 1) * cols];
    fill_n(hash_table, (rows + 1) * cols, 0);

    int res = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == '1') {
          int height = hash_table[row * cols + col] + 1;
          hash_table[(row + 1) * cols + col] = height;
          for (int _col = col; _col >= 0 && matrix[row][_col] == '1'; --_col) {
            height = min(height, hash_table[(row + 1) * cols + _col]);
            res = max(res, (col - _col + 1) * height);
          }
        }
      }
    }
    return res;
  }
};
