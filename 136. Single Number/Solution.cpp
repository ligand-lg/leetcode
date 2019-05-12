//
// Created by ligand on 2019-05-11.
//

/**
 * tag: # xor #
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      // 零异或任何数得该数
      int res = 0;
      for (auto n : nums) {
        res ^= n;
      }
      return res;
    }
};
