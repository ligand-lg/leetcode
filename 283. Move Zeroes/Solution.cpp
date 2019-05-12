//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int size = nums.size();
    int zero_cnt = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        zero_cnt++;
        continue;
      }
      if (zero_cnt != 0)
        nums[i - zero_cnt] = nums[i];
    }

    for (int i = size - 1; zero_cnt > 0; i--, zero_cnt--)
      nums[i] = 0;
  }
};
