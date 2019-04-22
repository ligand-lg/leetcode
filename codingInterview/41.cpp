//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> result;
    if (sum < 3) return result;
    int base = 0;
    int tmp;
    for (int n = sum / 2 + 1; n >= 2; n--) {
      tmp = sum - n * (n - 1) / 2;
      if (tmp > 0 && tmp % n == 0) {
        base = tmp / n;
        vector<int> r(n, 0);
        for (int i = 0; i < n; i++) {
          r[i] = base + i;
        }
        result.push_back(r);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  auto rs = s.FindContinuousSequence(100);
  for (auto r : rs) {
    for (auto n : r) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}
