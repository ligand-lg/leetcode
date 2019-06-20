/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    int new_position = 2, old_position = 2;
    while (old_position < size) {
      if (nums[old_position] == nums[new_position - 1] && nums[old_position] == nums[new_position - 2]) {
        ++old_position;
        continue;
      }
      nums[new_position++] = nums[old_position++];
    }
    return min(new_position, size);
  }
};
