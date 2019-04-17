#include "../leetcode.h"

class Solution {
public:
    int Fibonacci(int n) {
      int a = 0, b = 1;
      int tmp;
      for (;n > 0; n--) {
        tmp = b;
        b = a+b;
        a = tmp;
      }
      return a;
    }
};