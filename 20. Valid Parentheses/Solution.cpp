//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<char> tmp;
    for (auto c : s) {
      switch (c) {
        case ')':
          if (tmp.empty() || tmp.top() != '(')
            return false;
          tmp.pop();
          break;
        case ']':
          if (tmp.empty() || tmp.top() != '[')
            return false;
          tmp.pop();
          break;
        case '}':
          if (tmp.empty() || tmp.top() != '{')
            return false;
          tmp.pop();
          break;
        default:tmp.push(c);
      }
    }
    return tmp.empty();
  }
};
