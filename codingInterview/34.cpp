#include "../leetcode.h"

class Solution {
 public:
  int FirstNotRepeatingChar(string str) {
    int result = -1;
    vector<int> tmp(256, 0);
    for (auto c : str) {
      tmp[c] += 1;
    }
    for (int i = 0; i < str.size(); i++) {
      if (tmp[str[i]] == 1) {
        result = i;
        break;
      }
    }
    return result;
  }
};