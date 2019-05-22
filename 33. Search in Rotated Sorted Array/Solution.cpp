//
// Created by fry on 2019-05-22
//

/**
 *
 * T(n) = O(logn)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int rotated_binary_search(vector<int> &nums, int begin, int end, int target) {
    if (begin >= end)
      return -1;

    int mid = (begin + end) / 2;
    if (nums[mid] == target)
      return mid;

    // case 1   1,2,3
    if (nums[begin] < nums[mid] && nums[mid] < nums[end - 1]) {
      if (nums[mid] < target)
        return rotated_binary_search(nums, mid + 1, end, target);
      else
        return rotated_binary_search(nums, begin, mid, target);
    } else if (nums[begin] > nums[mid]) {
      // case 7,0,1,2
      if (nums[mid] < target && target <= nums[end - 1])
        return rotated_binary_search(nums, mid + 1, end, target);
      else
        return rotated_binary_search(nums, begin, mid, target);
    } else {
      // case 2,3,4,0,1
      if (nums[mid] > target && nums[begin] <= target)
        return rotated_binary_search(nums, begin, mid, target);
      else
        return rotated_binary_search(nums, mid + 1, end, target);
    }

  }
 public:
  int search(vector<int> &nums, int target) {
    return rotated_binary_search(nums, 0, nums.size(), target);
  }
};
