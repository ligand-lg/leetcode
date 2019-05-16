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
  void dfs(vector<vector<char>> &data, int row, int col) {
    if (0 <= row && row < data.size() && 0 <= col && col < data[0].size() && data[row][col] != '0') {
      data[row][col] = '0';
      dfs(data, row - 1, col);
      dfs(data, row + 1, col);
      dfs(data, row, col - 1);
      dfs(data, row, col + 1);
    }
  }

 public:
  int numIslands(vector<vector<char>> &grid) {
    vector<vector<char>> data(grid);
    int res = 0;
    if (data.empty() || data[0].empty())
      return res;

    for (int i = 0; i < data.size(); i++) {
      for (int j = 0; j < data[0].size(); j++)
        if (data[i][j] == '1') {
          dfs(data, i, j);
          res++;
        }
    }
    return res;
  }
};
