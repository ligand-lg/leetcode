//
// Created by fry on 2019-05-15
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> hash_table;

    int left, right, res, sum;
    res = 0;
    for (auto n : nums) {
      if (hash_table.find(n) == hash_table.end()) {
        left = right = 0;
        if (hash_table.find(n - 1) != hash_table.end())
          left = hash_table.at(n - 1);
        if (hash_table.find(n + 1) != hash_table.end())
          right = hash_table.at(n + 1);
        sum = left + right + 1;
        res = max(res, sum);
        // 更新边界，[n-left, n+right] 都已经在数组中
        hash_table[n] = sum;
        hash_table[n - left] = sum;
        hash_table[n + right] = sum;
      }
    }
    return res;
  }
};
