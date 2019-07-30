/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int minSubArrayLen(int s, const vector<int> &nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int left_index = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      while (sum >= s) {
        ans = min(ans, i - left_index + 1);
        sum -= nums[left_index++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
