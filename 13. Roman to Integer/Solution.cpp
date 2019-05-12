//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <string>

using namespace std;

class Solution {
  int single_roman2Int(char c) {
    switch (c) {
      case 'I':return 1;
      case 'V':return 5;
      case 'X':return 10;
      case 'L':return 50;
      case 'C':return 100;
      case 'D':return 500;
      case 'M':return 1000;
      default:return -1;
    }
  }
 public:
  int romanToInt(string s) {
    int res = 0;
    int size = s.size();

    for (int i = 0; i < size - 1; i++) {
      int cur_val = single_roman2Int(s[i]);
      if (cur_val < single_roman2Int(s[i + 1]))
        cur_val *= -1;
      res += cur_val;
    }
    res += single_roman2Int(s[size - 1]);

    return res;
  }
};
