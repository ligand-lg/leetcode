/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(const vector<int> &nums) {
    vector<vector<int>> v_res;
    // 诡异的语法
    v_res.emplace_back();

    for (auto n:nums) {
      int size = v_res.size();
      for (int i = 0; i < size; ++i) {
        v_res.push_back(v_res[i]);
        auto &item = v_res.back();
        item.push_back(n);
      }
    }

    // 去重
    vector<vector<int>> res;
    set<vector<int>> set_res;
    for (auto &item:v_res) {
      sort(item.begin(), item.end());
      if (set_res.find(item) == set_res.end()) {
        set_res.insert(item);
        res.push_back(item);
      }
    }
    return res;
  }
};
