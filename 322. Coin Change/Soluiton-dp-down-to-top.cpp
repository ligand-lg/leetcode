//
// Created by fry on 2019-05-23
//

/**
 *
 * T(n) = O(n*k)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount <= 0)
      return 0;
    if (coins.empty())
      return -1;

    vector<int> dp(amount + 1, 0);
    for (int i = 1; i <= amount; i++) {
      int res = -1;
      for (auto c: coins) {
        if (i - c >= 0 && dp[i - c] >= 0) {
          if (res == -1)
            res = dp[i - c];
          else
            res = min(res, dp[i - c]);
        }
      }
      if (res >= 0)
        ++res;
      dp[i] = res;
    }

    return dp[amount];
  }
};
