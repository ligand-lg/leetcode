//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * O(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int size = nums.size();
    int sum = (size + 1) * size / 2;
    int r_sum = 0;
    for (auto n : nums)
      r_sum += n;

    return sum - r_sum;
  }
};
