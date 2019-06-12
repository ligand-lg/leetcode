//
// Created by fry on 2019-05-31
//

/**
 *
 * T(n) = O(m+n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int rows = matrix.size(), cols = matrix[0].size();
    int row = 0, col = cols - 1;
    while (row < rows && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] > target) {
        // 当前元素是这列最小的元素，如果它比目标大，肯定不在这列中
        col--;
      } else {
        // 当前元素是这行最大的一个元素，如果它比目标小，肯定不在这行中
        row++;
      }
    }
    return false;
  }
};
