//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
 public:
  bool helper(char *s, char *p) {
    if (*s == '\0' && *p == '\0')
      return true;
    if (*s != '\0' && *p == '\0')
      return false;
    if (*(p + 1) == '*') {
      if (*p == *s || (*p == '.' && *s != '\0'))
        return helper(s + 1, p + 2) || helper(s + 1, p) || helper(s, p + 2);
      else
        return helper(s, p + 2);
    }
    if (*s == *p || (*p == '.' && *s != '\0'))
      return helper(s + 1, p + 1);
    return false;
  }
  bool match(char *str, char *pattern) {
    if (str == nullptr || pattern == nullptr)
      return false;
    return helper(str, pattern);
  }
};

int main() {
  Solution s;
  char str[] = "aaa";
  char p[] = ".*";
  cout << s.match(str, p);
}
