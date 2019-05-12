//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(2^n)
 * S(n) = O(2^n * n)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    // [] -> []
    if (nums.empty()) {
      vector<vector<int>> res;
      vector<int> empty;
      res.push_back(empty);
      return res;
    }
    //[a, [b]] -> a * f(b)
    vector<int> sub_nums(nums.begin() + 1, nums.end());
    vector<vector<int>> res = subsets(sub_nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
      vector<int> new_sub(res[i]);
      new_sub.push_back(nums[0]);
      res.push_back(new_sub);
    }
    return res;
  }
};
