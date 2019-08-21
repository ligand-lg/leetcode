#include "../leetcode.h"

// 斐波拉契数列变形
class Solution {
public:
    int rectCover(int number) {
      if (number <= 0) return 0;
      int a = 1;
      int b = 2;
      int tmp;
      for (int i = 1; i < number; ++i) {
        tmp = a + b;
        a = b;
        b = tmp;
      }
      return a;
    }
};