//
// Created by ligand on 2019-05-13.
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
  int missingNumber(vector<int> &nums) {
    const int size = nums.size();
    int res = 0;

    for (int i = 0; i <= size; i++)
      res ^= i;

    for (auto n:nums)
      res ^= n;

    return res;
  }
};
