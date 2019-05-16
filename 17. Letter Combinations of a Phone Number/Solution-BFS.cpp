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
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> res, pre_res;
    vector<string> &res_r = res, &pre_res_r = pre_res, tmp_r = res;

    if (digits.size() == 0)
      return res;

    pre_res_r.push_back(string());
    for (auto c: digits) {
      for (auto str:pre_res_r) {
        for (auto cha:digit2str[c]) {
          string new_str(str);
          new_str.push_back(cha);
          res_r.push_back(new_str);
        }
      }
      tmp_r = pre_res_r;
      pre_res_r = res_r;
      res_r = tmp_r;
      res_r.clear();
    }
    res_r = pre_res_r;
    return res_r;
  }
};
