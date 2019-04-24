//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
  map<pair<int, int>, int> dp;
  vector<int> data;
  int helper(int i, int j) {
    if (i > j)
      return 1;
    if (i == j)
      return data[i];

    pair<int, int> key(i, j);
    if (dp.find(key) == dp.end())
      dp[key] = helper(i, i) * helper(i + 1, j);
    return dp[key];
  }
 public:
  vector<int> multiply(const vector<int> &A) {
    this->data = A;
    int size = A.size();
    vector<int> res(size, 0);
    for (int i = 0; i < size; i++) {
      res[i] = helper(0, i - 1) * helper(i + 1, size - 1);
    }
    return res;
  }
};

int main() {
  Solution s;
  auto rs = s.multiply(vector<int>{1, 2, 3, 4, 5, 6, 7, 9, 10, 11});
  for (auto r: rs) {
    cout << r << "\t";
  }
  return 0;
}
