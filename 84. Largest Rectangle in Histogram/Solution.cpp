/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    if (heights.empty()) return 0;
    int size = heights.size();

    // 左边第一个高度低于当前高度的柱子
    vector<int> first_left_min_index(size);
    for (int i = 0; i < size; ++i) {
      int pre = i - 1;
      while (pre >= 0 && heights[pre] >= heights[i]) {
        // 注意这里的跳转。如果 pre 柱比 i 柱高（或一样高），那第一个比 pre 柱底的柱，而且比 i 柱底，则该柱为第一个比 i 柱底的柱
        pre = first_left_min_index[pre];
      }
      first_left_min_index[i] = pre;
    }

    // 右边第一个高度低于当前高度的柱子
    vector<int> first_right_min_index(size);
    for (int i = size - 1; i >= 0; --i) {
      int next = i + 1;
      while (next < size && heights[next] >= heights[i]) {
        next = first_right_min_index[next];
      }
      first_right_min_index[i] = next;
    }

    // 遍历每一个柱子，以该柱子为高的情况下（该柱子最低），计算最大值
    int res = heights[0];
    for (int i = 0; i < size; ++i) {
      res = max(res, heights[i] * (first_right_min_index[i] - first_left_min_index[i] - 1));
    }
    return res;
  }
};
