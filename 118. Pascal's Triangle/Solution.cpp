//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n^2)
 * S(n) = O(n^2)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows == 0)
      return res;

    res.push_back(vector<int>{1});
    // 第 i+1 行
    for (int i = 1; i < numRows; i++) {
      vector<int> line(i + 1);

      line[0] = 1;
      line[i] = 1;
      for (int j = 1; j < i; j++)
        line[j] = res[i - 1][j] + res[i - 1][j - 1];
      res.push_back(line);
    }

    return res;
  }
};
