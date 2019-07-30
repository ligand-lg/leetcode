/**
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int minSubArrayLen(int s, const vector<int> &nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> sums(n);
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + nums[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int sum = sums[j] - sums[i] + nums[i];
        if (sum >= s) {
          ans = min(ans, j - i + 1);
          break;
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
