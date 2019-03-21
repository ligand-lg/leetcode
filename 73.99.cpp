#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool isFirstRowZero = false;
    bool isFirstColZero = false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    // 第一行是否存在零
    for (int j = 0; j < cols; j++) {
      if (matrix[0][j] == 0) {
        isFirstRowZero = true;
        break;
      }
    }
    // 第一列是否存在零
    for (int i = 0; i < rows; i++) {
      if (matrix[i][0] == 0) {
        isFirstColZero = true;
        break;
      }
    }
    // 遍历所有，除了第一行和第一列。发现零，将对应的行头和列头置为零
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    // 遍历所有，除了第一行和第一列。如何行头或列头为零，则将该值设置为零
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (isFirstRowZero) {
      for (int j = 0; j < cols; j++) {
        matrix[0][j] = 0;
      }
    }
    if (isFirstColZero) {
      for (int i = 0; i < rows; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};