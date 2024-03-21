#include "../leetcode.h"

class Solution {
public:
  int maximalSquare(const vector<vector<char>> &matrix) {
    size_t cols = matrix[0].size();

    // dps 是以前一行每个元素为右下角，能组成最大全1正方形的边长
    // colContinueOnes 是前一行往上数，最长连续1的个数
    vector<int> dps(cols, 0), tmpDPs(cols, 0), colContinueOnes(cols, 0);
    int res = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      int lineContinueOnes = matrix[i][0] - '0';
      tmpDPs[0] = matrix[i][0] - '0';
      res = max((matrix[i][0] - '0'), res);

      for (int j = 1; j < cols; ++j) {
        if (matrix[i][j] == '0') {
          tmpDPs[j] = 0;
          colContinueOnes[j] = 0;
          lineContinueOnes = 0;
        } else {
          tmpDPs[j] =
              min(min(dps[j - 1], lineContinueOnes), colContinueOnes[j]) + 1;
          res = max(res, tmpDPs[j]);
          colContinueOnes[j] += 1;
          lineContinueOnes += 1;
        }
      }
      dps.swap(tmpDPs);
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