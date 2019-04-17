#include "../leetcode.h"

class Solution {
  vector<int> dp;
  int helper(int n) {
    if (dp[n] < 0) {
      dp[n] = helper(n-1) + helper(n-2);
    }
    return dp[n];
  }
 public:
  int jumpFloor(int number) {
    if (number <= 0) return 0;
    dp = vector<int>(number+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return helper(number);
  }
};