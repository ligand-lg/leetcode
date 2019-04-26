//
// Created by ligand on 2019-04-26.
//

#include "../leetcode.h"

class Solution {
  char *data;
  int _rows;
  int _cols;
  const char used_mark = '\0';

  bool helper(int row, int col, const char *s) {
    if (*s == '\0')
      return true;

    if (row < 0 || col < 0 || row >= _rows || col >= _cols)
      return false;

    int index = row * _cols + col;

    if (data[index] == used_mark)
      return false;

    if (data[index] == *s) {
      data[index] = used_mark;
      bool res = helper(row, col - 1, s + 1) ||
          helper(row, col + 1, s + 1) ||
          helper(row + 1, col, s + 1) ||
          helper(row - 1, col, s + 1);
      data[index] = *s;
      return res;
    }
    return false;
  }

 public:
  bool hasPath(char *matrix, int rows, int cols, char *str) {
    if (matrix == nullptr || str == nullptr || rows <= 0 || cols <= 0)
      return false;
    data = matrix;
    _rows = rows;
    _cols = cols;
    bool res = false;
    for (int i = 0; !res && i < rows; i++) {
      for (int j = 0; !res && j < cols; j++) {
        res = helper(i, j, str);
      }
    }
    return res;
  }
};
