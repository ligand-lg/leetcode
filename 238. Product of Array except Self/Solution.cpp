//
// Created by ligand on 2019-05-11.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.size() < 2)
      return vector<int>();

    int size = nums.size();
    vector<int> pre_n_1(size), last_n_1(size), res(nums);

    pre_n_1[0] = 1;
    for (int i = 1; i < size; i++)
      pre_n_1[i] = pre_n_1[i - 1] * nums[i - 1];

    last_n_1[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--)
      last_n_1[i] = last_n_1[i + 1] * nums[i + 1];

    for (int i = 0; i < size; i++)
      res[i] = last_n_1[i] * pre_n_1[i];

    return res;
  }
};
