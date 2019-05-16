//
// Created by fry on 2019-05-16
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    queue<pair<int, int>> tmp;

    vector<vector<char>> data(grid);
    int res = 0;
    if (data.empty() || data[0].empty())
      return res;

    int row, col, rows, cols;
    rows = data.size();
    cols = data[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (data[i][j] == '1') {
          tmp.push(make_pair(i, j));
          while (!tmp.empty()) {
            row = tmp.front().first;
            col = tmp.front().second;
            tmp.pop();
            if (0 <= row && row < rows && 0 <= col && col < cols && data[row][col] == '1') {
              data[row][col] = '0';
              tmp.push(make_pair(row - 1, col));
              tmp.push(make_pair(row + 1, col));
              tmp.push(make_pair(row, col - 1));
              tmp.push(make_pair(row, col + 1));
            }
          }
          res++;
        }
      }
    }
    return res;
  }
};
