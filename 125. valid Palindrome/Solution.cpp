//
// Created by fry on 2019-05-23
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int lowCase(char c) {
    if (c >= 'A' && c <= 'Z')
      c -= 'A';
    else if (c <= 'z' && c >= 'a')
      c -= 'a';
    else if (c <= '9' && c >= '0')
      c = c - '0' + 'z';
    else
      c = -1;
    return (int) c;
  }

 public:
  bool isPalindrome(const string &s) {
    int start = 0, end = s.size() - 1;
    int a, b;
    while (start < end) {
      a = lowCase(s[start]);
      b = lowCase(s[end]);
      if (a == -1) {
        ++start;
        continue;
      } else if (b == -1) {
        --end;
        continue;
      }
      if (a != b)
        return false;
      ++start;
      --end;
    }
    return true;
  }
};
