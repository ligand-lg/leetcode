#include "../leetcode.h"

class Solution {
public:
  int maximalSquare(const vector<vector<char>> &matrix) {
    int res = 0;
    size_t m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (size_t row = 1; row <= m; ++row) {
      for (size_t col = 1; col <= n; ++col) {
        if (matrix[row - 1][col - 1] == '1') {
          dp[row][col] =
              min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]}) +
              1;
          res = max(res, dp[row][col]);
        }
      }
    }

    return res * res;
  }
};

int main() {
  Solution s;
  vector<vector<char>> data;
  data.push_back({'1', '0', '1', '0'});
  data.push_back({'1', '0', '1', '1'});
  data.push_back({'1', '0', '1', '1'});
  data.push_back({'1', '1', '1', '1'});
  int res = s.maximalSquare(data);
  cout << res;
}