/**
 *
 * T(n) = O(logn)
 * S(n) = O(1)
 */
#include "../leetcode.h"

class Solution {
  int aux(const vector<int> &nums, int first, int last) {
    // 出口
    if (last - first < 3) {
      if (last - first == 2) {
        return min(nums[first], nums[first + 1]);
      } else if (last - first == 1) {
        return nums[first];
      }
      return -1;
    }
    int mid = (first + last) / 2;
    if (nums[mid] > nums[last - 1])
      return aux(nums, mid, last);
    else
      return aux(nums, first, mid + 1);
  }

 public:
  int findMin(const vector<int> &nums) { return aux(nums, 0, nums.size()); }
};

