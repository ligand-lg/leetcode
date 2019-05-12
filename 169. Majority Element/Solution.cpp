//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    if (nums.empty())
      return -1;
    int res = -1;
    int cnt = 0;
    for (auto n : nums) {
      if (cnt == 0) {
        res = n;
        cnt = 1;
        continue;
      }
      // cnt > 0
      if (n == res)
        cnt++;
      else
        cnt--;
    }
    return res;
  }
};
