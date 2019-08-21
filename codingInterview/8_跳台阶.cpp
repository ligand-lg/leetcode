#include "../leetcode.h"

// 斐波拉契数列变形
class Solution {
 public:
  int jumpFloor(int number) {
    if (number <= 0) return -1;
    int a = 1;
    int b = 2;
    for (int i = 1; i < number; ++i) {
      int tmp = a + b;
      a = b;
      b = tmp;
    }
    return a;
  }
};