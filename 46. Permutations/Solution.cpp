//
// Created by ligand on 2019-05-11.
//

/**
 * tag: # Backtracking #
 * T(n) = O(n!)
 * S(n) = O(n^2)
 */

#include <vector>
using namespace std;

class Solution {

  void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void help(vector<int> &nums, int start_index) {
    if (start_index >= nums.size() - 1) {
      res.push_back(nums);
      return;
    }
    for (int i = start_index; i < nums.size(); i++) {
      swap(nums, i, start_index);
      help(nums, start_index + 1);
      swap(nums, i, start_index);
    }
  }
  vector<vector<int>> res;

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.empty())
      return res;
    help(nums, 0);
    return res;
  }
};
