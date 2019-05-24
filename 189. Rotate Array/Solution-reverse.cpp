//
// Created by fry on 2019-05-24
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    if (k <= 0 || nums.empty())
      return;

    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
  }
};
