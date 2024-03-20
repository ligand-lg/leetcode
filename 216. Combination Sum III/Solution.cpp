#include "../leetcode.h"

class Solution {
public:
  // idx 当前遍历到第i个元素
  vector<vector<int>> help(int k, int n, int idx) {
    if (k == 1) {
      if (idx <= n && n <= 9) {
        return {{n}};
      } else {
        return {};
      }
    }
    if (idx >= n) {
      return {};
    }
    vector<vector<int>> res;
    for (int i = idx; i < 9; i++) {
      for (auto r : help(k - 1, n - i, i + 1)) {
        r.push_back(i);
        res.push_back(r);
      }
    }
    return res;
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    if (k < 1) {
      return {};
    }
    return help(k, n, 1);
  }
};

int main() {
  Solution s;
  auto res = s.combinationSum3(2, 18);
  cout << res[0][0];
}