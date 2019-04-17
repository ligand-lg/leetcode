#include "../leetcode.h"

class Solution {
  vector<int> dp;
  int helper(int n) {
    if (dp[n] < 0) {
      int result = 1;
      for (int i =1; i < n; i++) {
        result += helper(i);
      }
      dp[n] = result;
    }
    return dp[n];
  }
 public:
  int jumpFloorII(int number) {
    if (number <= 0) return 0;
    dp = vector<int>(number+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return helper(number);
  }
};