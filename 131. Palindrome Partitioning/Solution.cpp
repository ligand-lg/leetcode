//
// Created by fry on 2019-05-29
//

/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
  bool isPalindrome(int s, int e) {
    while (s < e) {
      if (str[s] != str[e])
        return false;
      s++;
      e--;
    }
    return true;
  }
  void dfs(int i, vector<string> &one_res) {
    if (i == str.size()) {
      res.emplace_back(one_res);
      return;
    }
    // 从 i 到 j
    for (int j = i; j < str.size(); j++) {
      if (isPalindrome(i, j)) {
        one_res.push_back(str.substr(i, j - i + 1));
        dfs(j + 1, one_res);
        // backtrace
        one_res.pop_back();
      }
    }
  }
  string str;
  vector<vector<string>> res;

 public:
  vector<vector<string>> partition(string s) {
    str = s;
    res = vector<vector<string>>();
    vector<string> tmp;
    dfs(0, tmp);
    return res;
  }
};
