/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  bool b_search(const vector<int> &nums, int begin, int end, int target) {
    if (begin >= end) return false;
    int mid = (begin + end) / 2;
    if (nums[mid] == target) return true;

    while (begin < mid && nums[begin] == nums[mid]) ++begin;
    while (end > mid && nums[mid] == nums[end - 1]) --end;
    if (end == mid) end = mid + 1;

    // case1 1,2,3
    if (nums[begin] < nums[mid] && nums[mid] < nums[end - 1]) {
      if (nums[mid] < target)
        return b_search(nums, mid + 1, end, target);
      else
        return b_search(nums, begin, mid, target);
    } else if (nums[begin] > nums[mid]) {
      // case2 3,1,2
      if (nums[mid] < target && target <= nums[end - 1])
        return b_search(nums, mid + 1, end, target);
      else
        return b_search(nums, begin, mid, target);
    } else {
      // case3 2,3,1
      if (target < nums[mid] && target >= nums[begin])
        return b_search(nums, begin, mid, target);
      else
        return b_search(nums, mid + 1, end, target);
    }
  }
 public:
  bool search(const vector<int> &nums, int target) {
    return b_search(nums, 0, nums.size(), target);
  }
};


