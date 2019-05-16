//
// Created by fry on 2019-05-16
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  void dfs(string &one, string &digits, int index) {
    if (index == digits.size()) {
      res.push_back(one);
      return;
    }
    for (auto c : digit2str[digits[index]]) {
      one[index] = c;
      dfs(one, digits, index + 1);
    }
  }
  unordered_map<char, string> digit2str = {
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"}
  };
  vector<string> res;
 public:
  vector<string> letterCombinations(string digits) {
    res = vector<string>();
    if (digits.size() == 0)
      return res;

    string line(digits.size(), '-');
    dfs(line, digits, 0);
    return res;
  }
};
