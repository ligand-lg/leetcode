//
// Created by ligand on 2019-05-15.
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
  void sortColors(vector<int> &nums) {
    int zero_cnt = 0;
    int one_cnt = 0;
    int two_cnt = 0;

    // one turn - count
    for (auto n : nums) {
      if (n == 0)
        zero_cnt++;
      else if (n == 1)
        one_cnt++;
      else if (n == 2)
        two_cnt++;
    }

    // two turn - set
    int i = 0;
    while (zero_cnt > 0) {
      nums[i++] = 0;
      zero_cnt--;
    }
    while (one_cnt > 0) {
      nums[i++] = 1;
      one_cnt--;
    }
    while (two_cnt > 0) {
      nums[i++] = 2;
      two_cnt--;
    }
  }
};
