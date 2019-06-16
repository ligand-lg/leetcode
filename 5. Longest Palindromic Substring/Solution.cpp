/**
 *
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int expandAroundCenter(const string &str, int left, int right) {
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
      --left;
      ++right;
    }
    return (right - left - 1);
  }
 public:
  string longestPalindrome(const string &s) {
    if (s.empty()) {
      return "";
    }
    int max_start = 0, max_size = 1;
    int size1 = 0, size2 = 0, size = 0;
    for (int i = 0; i < s.size(); ++i) {
      size1 = expandAroundCenter(s, i, i);
      size2 = expandAroundCenter(s, i, i + 1);
      size = max(size1, size2);
      if (size > max_size) {
        max_size = size;
        max_start = i - (max_size - 1) / 2;
      }
    }
    return s.substr(max_start, max_size);
  }
};
