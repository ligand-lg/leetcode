//
// Created by ligand on 2019-05-12.
//

/**
 * 算法上讲，hash 时间上应该优于 排序，但实际则相反
 * T(n) = O(n * log(n))
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int end = nums.size() - 1;
    for (int i = 0; i < end; i++) {
      if (nums[i] == nums[i + 1])
        return true;
    }
    return false;
  }
};
