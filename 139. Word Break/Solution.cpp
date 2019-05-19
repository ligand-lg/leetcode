//
// Created by fry on 2019-05-19
//

/**
 * 转移方程: f(n) = f(n-len(w[i])) i = [...wordDict], w[i] == str[i-size(w[i]), i]
 *          f(0) = true;
 * T(n) = O(n*m)
 * S(n) = O(n)
*/

#include "../leetcode.h"

class Solution {
  bool help(int end_index) {
    // 匹配完成
    if (end_index == 0)
      return true;

    // 有缓存记录，不可达
    if (dp[end_index])
      return false;

    for (const auto &s: wd) {
      if (end_index >= s.size()) {
        string sub_str = str.substr(end_index - s.size(), s.size());
        if (sub_str == s && help(end_index - s.size()))
          return true;
      }
    }
    // 标记不可达
    dp[end_index] = true;
    return false;
  }

  // true 表示不能达到，false 表示没有初始化
  vector<bool> dp;
  string str;
  vector<string> wd;

 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    this->str = s;
    this->wd = wordDict;
    dp = vector<bool>(s.size() + 1, false);
    return help(s.size());
  }
};
