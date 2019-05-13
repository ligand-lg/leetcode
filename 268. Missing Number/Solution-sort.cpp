//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n * log(n))
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int i = 0;
    for (; i < size; i++) {
      if (i != nums[i])
        return i;
    }
    return i;
  }
};
