//
// Created by fry on 2019-05-30
//

/**
 *
 * T(n) = O(logm + log n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int row = -1;
    int begin = 0, end = matrix.size();
    while (begin < end) {
      int mid = (begin + end) / 2;
      if (matrix[mid][0] > target) {
        end = mid;
      } else if (matrix[mid].back() < target) {
        begin = mid + 1;
      } else {
        row = mid;
        break;
      }
    }
    if (row < 0)
      return false;

    begin = 0, end = matrix[row].size();
    while (begin < end) {
      int mid = (begin + end) / 2;
      if (matrix[row][mid] == target) {
        return true;
      } else if (matrix[row][mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return false;
  }
};

