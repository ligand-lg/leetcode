//
// Created by fry on 2019-05-21
//

/**
 *
 * T(n) = O(logn)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int binary_search(vector<int> &nums, int target, bool left) {
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = (begin + end) / 2;
      if (nums[mid] > target || (left && target == nums[mid]))
        end = mid;
      else
        begin = mid + 1;
    }
    return begin;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int left_index = binary_search(nums, target, true);
    if (left_index == nums.size() || nums[left_index] != target)
      return vector<int>{-1, -1};
    return vector<int>{left_index, binary_search(nums, target, false) - 1};
  }
};

int main() {

}
