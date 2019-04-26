//
// Created by ligand on 2019-04-26.
//

#include "../leetcode.h"

class Solution {
  bool *visited;
  int _rows;
  int _cols;
  int k;
  int helper(int row, int col) {
    if (row < 0 || col < 0 || row >= _rows || col >= _cols)
      return 0;
    int index = row * _cols + col;

    if (visited[index])
      return 0;

    visited[index] = true;
    if (f(row) + f(col) <= k)
      return 1 + helper(row, col - 1) + helper(row, col + 1) + helper(row - 1, col) + helper(row + 1, col);
    return 0;
  }
  // f(12) = 1+2 = 3;
  int f(unsigned int n) {
    int res = 0;
    while (n != 0) {
      res += n % 10;
      n = n / 10;
    }
    return res;
  }

 public:
  int movingCount(int threshold, int rows, int cols) {
    int num = rows * cols;

    visited = new bool[num];
    _rows = rows;
    _cols = cols;
    k = threshold;

    for (int i = 0; i < num; i++) visited[i] = false;

    int res = helper(0, 0);

    delete []visited;

    return res;
  }
};
