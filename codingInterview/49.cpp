//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  int StrToInt(string str) {
    int err = 0;
    int start, end, signal;
    bool hasSignal = false;
    signal = 1;
    char c;

    for (start = 0; start < str.length(); start++) {
      c = str[start];
      // 数字位
      if ('0' <= c && c <= '9') break;
        // 开头空格
      else if (' ' == c) continue;
        // 开头第一个符号
      else if (('-' == c || '+' == c) && !hasSignal) {
        hasSignal = true;
        signal = c == '-' ? -1 : 1;
      } else {
        // 非法字符
        return err;
      }
    }

    for (end = str.length() - 1; end >= start; end--) {
      c = str[end];
      if ('0' <= c && c <= '9') break;
      else if (' ' == c) continue;
      else {
        return err;
      }
    }

    long result;
    result = 0;
    for (int i = start; i <= end; i++) {
      c = str[i];
      if ('0' <= c && c <= '9') {
        result = result * 10 + c - '0';
        // check overflow
        if (result < 0)
          return err;
      } else {
        return err;
      }
    }
    result *= signal;
    // check overflow
    if (INT_MAX < result || INT_MIN > result)
      return err;
    return result;
  }
};

int main() {
  Solution s;
  cout << s.StrToInt("");
  return 0;
}
