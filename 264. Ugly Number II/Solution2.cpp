#include "../leetcode.h"

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    size_t x = 1, y = 1, z = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = min({dp[x] * 2, dp[y] * 3, dp[z] * 5});
      if (dp[i] == 2 * dp[x])
        ++x;
      if (dp[i] == 3 * dp[y])
        ++y;
      if (dp[i] == 5 * dp[z])
        ++z;
    }

    return dp[n];
  }
};
