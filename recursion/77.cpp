#include "../leetcode.h"

/*
 * 递归方程: f(n, k) = [...f(n-1, k-1) +n , ...f(n-1, k)]，其中 n >= k > 0;
 * 递归出口: f(n, k) = [[]]，其中 n >0, k = 0;
 *          f(n, k) = []
 *
 * T(n) = O(n*m)，其中 n 为目标字符串长度，m 为字典元素个数;
 * S(n) = O(n);
 */

class Solution {
  // key: (n, k), value: [[]]
  map<pair<int, int>, vector<vector<int>>> dp;

 public:
  vector<vector<int>> combine(int n, int k) {
    if (n >= k && k > 0) {
      // check 缓存，有直接使用，没有算下来，存入缓存。
      vector<vector<int>> result;
      auto find = dp.find(pair<int, int>(n, k));
      if (find == dp.end()) {
        for (auto r : combine(n - 1, k - 1)) {
          r.push_back(n);
          result.push_back(r);
        }
        for (auto r : combine(n - 1, k)) {
          result.push_back(r);
        }
        dp[pair<int, int>(n, k)] = result;
      } else {
        result = find->second;
      }
      return result;
    } else if (n >= 0 && k == 0) {
      // [[]]
      return vector<vector<int>>(1);
    }
    // []
    return vector<vector<int>>();
  }
};

int main() {
  Solution s;
  for (auto r : s.combine(1, 1)) {
    for (int i : r) {
      cout << i << " ";
    }
    cout << endl;
  }
}