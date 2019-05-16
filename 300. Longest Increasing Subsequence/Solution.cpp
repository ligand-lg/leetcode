//
// Created by fry on 2019-05-16
//

/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
  pair<bool, int> binary_search(vector<int> &data, int start, int end, int val) {
    if (start >= end)
      return make_pair(false, end);

    int mid = (start + end) / 2;
    if (data[mid] == val)
      return make_pair(true, mid);

    if (data[mid] > val)
      return binary_search(data, start, mid, val);

    return binary_search(data, mid + 1, end, val);
  }

 public:
  int lengthOfLIS(vector<int> &nums) {
    int res = 0;
    if (nums.empty())
      return res;

    vector<int> dp(nums.size());
    int i;
    for (auto n: nums) {
      auto find_res = binary_search(dp, 0, res, n);
      dp[find_res.second] = n;
      // 扩展了一位
      if (find_res.second == res)
        res++;
    }
    return res;
  }
};
