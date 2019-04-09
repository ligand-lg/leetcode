#include "leetcode.h"

// 
class Solution {
 public:
  int maxProfit(int k, vector<int> &prices) {
    int count = prices.size();
    if (count < 2) return 0;

    vector<vector<int> > dp(k + 1, vector<int>(count, 0));
    int k_i, i, j;
    int tmp_max = 0;

    // dp[k,i] = max(dp[k, i-1], ai- aj + dp[k-1, j-1]), j = [0...i-1];
    for (k_i = 1; k_i <= k; k_i++) {
      for (i = 1; i < count; i++) {
        tmp_max = max(dp[k_i][i - 1], prices[i] - prices[0]);
        for (j = 1; j < i; j++) {
          tmp_max = max(tmp_max, prices[i] - prices[j] + dp[k_i - 1][j - 1]);
        }
        dp[k_i][i] = tmp_max;
      }
    }
    return dp[k][count - 1];
  }
};

int main() {
  int k = 1000000000;
  Solution s;
  cout << s.maxProfit(2, data);
  return 0;
}
