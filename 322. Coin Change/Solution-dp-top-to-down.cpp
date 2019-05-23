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
  vector<int> dp;
  int help(const vector<int> &coins, int amount) {
    if (amount < 0)
      return -1;
    if (dp[amount] != -2)
      return dp[amount];

    int res = -1;
    for (auto c:coins) {
      int r = help(coins, amount - c);
      if (r != -1) {
        if (res == -1)
          res = r + 1;
        else
          res = min(res, r + 1);
      }
    }

    dp[amount] = res;
    return res;
  }

 public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount <= 0)
      return 0;
    if (coins.empty())
      return -1;

    dp = vector<int>(amount + 1, -2);
    dp[0] = 0;
    return help(coins, amount);
  }
};
