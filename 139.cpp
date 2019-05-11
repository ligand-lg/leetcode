#include "leetcode.h"

/*
 *
 * 转移方程: f(n) = max(f(n-len(w[i]))) i = [...wordDict];
 *          f(0) = 1;
 *          f(n) = -1 (n < 0);
 * T(n) = O(n*m)
 * S(n) = O(n)
 */

class Solution {
  vector<int> dp;
  string str;
  vector<string> wd;
  int it(int i) {
    // 已经有缓存，直接使用
    if (dp[i] != 0) return dp[i];

    // 没有缓存，计算
    for (auto s : wd) {
      int start_index = i - s.length();
      // 当前串比word长
      if (start_index >= 0) {
        // 比较两个字符串完全相等
        bool is_same = true;
        for (auto c : s) {
          if (c != str[start_index++]) {
            is_same = false;
            break;
          }
        }
        if (is_same && it(i - s.length()) == 1) {
          dp[i] = 1;
          return 1;
        }
      }
    }
    dp[i] = -1;
    return -1;
  }

 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int count = s.length();
    this->str = s;
    this->wd = wordDict;
    // 0 表示没有初始化， 1 表示能成功， -1 表示失败
    this->dp = vector<int>(count + 1, 0);
    dp[0] = 1;
    return it(count) == 1;
  }
};

int main() {
  Solution s;
  vector<string> data{"li", "gand"};
  auto r = s.wordBreak("ligand", data);
  cout << "result: " << r;
  return 0;
}
