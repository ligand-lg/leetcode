#include "../leetcode.h"

class Solution {
public:
  bool isInt(string s) {
    if (s.length() == 0) {
      return false;
    }

    int i = 0;
    if ((s.length() > 1) && (s[0] == '-' || s[0] == '+')) {
      i = 1;
    }
    while (i < s.length()) {
      if (s[i] < '0' || s[i] > '9') {
        return false;
      }
      i += 1;
    }

    return true;
  }

  bool isDecimal(string s) {
    if (s.length() == 0) {
      return false;
    }

    int i = 0;
    bool find_dot = false;
    bool find_digit = false;

    if ((s.length() > 1) && (s[0] == '-' || s[0] == '+')) {
      i = 1;
    }
    while (i < s.length()) {
      if (s[i] >= '0' && s[i] <= '9') {
        find_digit = true;
      } else if (s[i] == '.') {
        if (find_dot) {
          return false;
        }
        find_dot = true;
      } else {
        return false;
      }

      i += 1;
    }

    return find_digit;
  }

  bool isNumber(string s) {
    int e_index = -1;
    for (int i = 0; i <= s.length() - 1; i++) {
      if (s[i] == 'e' || s[i] == 'E') {
        e_index = i;
        break;
      }
    }

    if (e_index != -1) {
      string pre = s.substr(0, e_index);
      return (isInt(pre) || isDecimal(pre)) &&
             isInt(s.substr(e_index + 1, s.length() - e_index + 1));
    } else {
      return isInt(s) || isDecimal(s);
    }
  }
};

int main() {
  Solution s;
  bool res = s.isNumber("0");       // t
  res = s.isNumber("e");            // f
  res = s.isNumber(".");            // f
  res = s.isNumber("+6e-1");        // t
  res = s.isNumber("-123.456e789"); // t
  res = s.isNumber("95a54e53");     // f
  res = s.isNumber("99e2.5");       // f
}