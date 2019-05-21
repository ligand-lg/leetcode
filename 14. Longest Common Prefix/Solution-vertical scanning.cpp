//
// Created by fry on 2019-05-21
//

/**
 *
 * T(n) = O(n*k)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string> &sts) {
    if (sts.empty())
      return "";
    if (sts.size() == 1)
      return sts[0];

    string res;
    int min_str_len = sts[0].size();
    for (const auto &s:sts)
      min_str_len = min(min_str_len, (int) s.size());

    bool err = false;
    for (int i = 0; !err && i < min_str_len; i++) {
      char c = 0;
      for (const auto &s : sts) {
        if (c == 0)
          c = s[i];
        else if (c != s[i]) {
          err = true;
          break;
        }
      }

      if (!err)
        res.push_back(c);
    }
    return res;
  }
};
