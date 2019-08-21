#include "../leetcode.h"

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
      vector<int> res;
      if (matrix.empty() || matrix[0].empty()) return res;
      int min_row = 0;
      int max_row = matrix.size() - 1;
      int min_col = 0;
      int max_col = matrix[0].size() - 1;
      while(min_row <= max_row && min_col <= max_col) {
        for (int col = min_col; col <= max_col; ++col) {
          res.push_back(matrix[min_row][col]);
        }
        ++min_row;
        if (min_row > max_row) break;
        
        for (int row = min_row; row <= max_row; ++row) {
          res.push_back(matrix[row][max_col]);
        }
        --max_col;
        if (min_col > max_col) break;
        
        for (int col = max_col; col >= min_col; --col) {
          res.push_back(matrix[max_row][col]);
        }
        --max_row;
        if (min_row > max_row) break;
        
        for (int row = max_row; row >= min_row; --row) {
          res.push_back(matrix[row][min_col]);
        }
        ++min_col;
      }
      return res;
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