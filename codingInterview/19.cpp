#include "../leetcode.h"

class Solution {
 public:
  vector<int> printMatrix(vector<vector<int>> matrix) {
    vector<int> result;
    if (matrix.size() == 0 || matrix[0].size() == 0) return result;

    int row = matrix.size();
    int col = matrix[0].size();
    int start_x = 0;
    int start_y = 0;
    while (row > 0 && col > 0) {
      // left to right
      int x = start_x, y = start_y;
      for (x = start_x; x < start_x + col; x++) {
        result.push_back(matrix[y][x]);
      }

      // up to down
      x = start_x + col - 1;
      for (y = start_y + 1; y < start_y + row; y++) {
        result.push_back(matrix[y][x]);
      }

      // right to left
      y = start_y + row - 1;
      if (row > 1) {
        for (x -= 1; x >= start_x; x--) {
          result.push_back(matrix[y][x]);
        }
      }

      // down to up
      x = start_x;
      if (col > 1) {
        for (y -= 1; y > start_y; y--) {
          result.push_back(matrix[y][x]);
        }
      }
      row -= 2;
      col -= 2;
      start_x += 1;
      start_y += 1;
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> test_case;
  test_case.push_back(vector<int>{1});
  test_case.push_back(vector<int>{2});
  auto ans = s.printMatrix(test_case);
  for (auto s : ans) {
    cout << s << endl;
  }
  return 0;
}