//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    if (nums.empty())
      return 0;

    int size = nums.size();
    bool *hash_table = new bool[size + 1];
    memset(hash_table, 0, sizeof(bool) * (size + 1));

    for (auto n : nums)
      hash_table[n] = true;

    for (int i = 0; i < size; i++) {
      if (!hash_table[i])
        return i;
    }
    return size;
  }
};
