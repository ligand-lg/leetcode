#include "../leetcode.h"

// 可使用数学归纳法证明
class Solution {
public:
    int jumpFloorII(int number) {
      return number > 0 ? pow(2, number-1) : 0;
    }
};