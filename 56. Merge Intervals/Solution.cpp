//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int size = intervals.size();
    vector<vector<int>> res;
    if (size == 0)
      return res;

    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < size - 1; i++) {
      // 左边界相等，去右届最大
      if (intervals[i][0] == intervals[i + 1][0])
        intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
      // 左边界不等，有交集
      if (intervals[i][1] >= intervals[i + 1][0]) {
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
      }
        // 左边界不等，无交集
      else {
        res.push_back(intervals[i]);
      }
    }
    res.push_back(intervals[size - 1]);
    return res;
  }
};
