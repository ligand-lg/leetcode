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
    vector<vector<int>> res;
    res.emplace_back();

    for (auto n : nums) {
      int size = res.size();
      for (int i = 0; i < size; ++i) {
        res.push_back(res[i]);
        auto &item = res.back();
        item.push_back(n);
      }
    }
    return res;
  }
};
