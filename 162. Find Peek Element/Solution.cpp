#include "../leetcode.h"

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = (right + left) / 2;

      bool is_left_greater = (mid > 0) && (nums[mid - 1] > nums[mid]);
      bool is_right_greater =
          (mid < nums.size() - 1) && (nums[mid + 1] > nums[mid]);

      if (is_left_greater) {
        right = mid - 1;
      } else if (is_right_greater) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
