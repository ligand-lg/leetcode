//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int res = nums[0], pre_max = max(0, nums[0]);

    const int size = nums.size();
    for (int i = 1; i < nums.size(); i++) {
      res = max(res, nums[i] + pre_max);
      pre_max = max(0, nums[i] + pre_max);
    }

    return res;
  }
};
