//
// Created by fry on 2019-05-26
//

/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    int end = nums.size() - 1;
    for (int i = 0; i < end; ++i) {
      if (tmp[i] == tmp[i + 1])
        return tmp[i];
    }
    return -1;
  }
};
