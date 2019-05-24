//
// Created by fry on 2019-05-24
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    if (nums.empty() || k <= 0)
      return;

    int size = nums.size();
    vector<int> tmp(size);
    k = size - (k % size);
    int j = 0;

    for (int i = k; i < size; ++i) {
      tmp[j++] = nums[i];
    }
    for (int i = 0; i < k; ++i) {
      tmp[j++] = nums[i];
    }
    for (int i = 0; i < size; ++i) {
      nums[i] = tmp[i];
    }
  }
};

int main() {
  Solution s;
  vector<int> test_case = {1, 2, 3, 4, 5, 6, 7};
  s.rotate(test_case, 3);
  for (auto n : test_case)
    cout << n << ",";
}
