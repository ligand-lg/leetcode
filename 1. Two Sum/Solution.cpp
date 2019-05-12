//
// Created by ligand on 2019-05-11.
//
#include <vector>

/**
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{i, j};
        }
      }
    }
    return vector<int>{-1, -1};
  }
};
