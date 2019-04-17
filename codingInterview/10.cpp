#include "../leetcode.h"

class Solution {
public:
    int rectCover(int number) {
      if (number < 1) return 0;
      int a = 1, b = 2;
      int tmp;
      for (; number > 1; number--) {
        tmp = b;
        b += a;
        a = tmp;
      }
      return a;
    }
};