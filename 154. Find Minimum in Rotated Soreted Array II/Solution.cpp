/**
 *
 * T(n) = O(logn)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int aux(const vector<int> &nums, int first, int last) {
    if (last - first < 3) {
      return last - first == 2 ?
             min(nums[first], nums[first + 1]) :
             nums[first];
    }
    int mid = (first + last) / 2;
    int c = nums[mid];
    int b = nums[last - 1];
    if (c > b)
      return aux(nums, mid, last);
    else if (c < b)
      return aux(nums, first, mid + 1);
    else {
      // 中间值和最后一个元素相等，从中间向右找，找一个第一个不一样的元素。
      int c_right = c;
      int mid_right = mid;
      while (c_right == c && mid_right < last) {
        c_right = nums[mid_right];
        ++mid_right;
      }
      if (c_right == c)
        return aux(nums, first, mid + 1);
      else if (c_right > c) {
        c = c_right;
        mid = mid_right;
        return c > b ? aux(nums, mid, last) : aux(nums, first, mid + 1);
      } else
        return c_right;
    }
  }
 public:
  int findMin(const vector<int> &nums) {
    return aux(nums, 0, nums.size());
  }
};
