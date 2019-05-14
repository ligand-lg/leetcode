//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int> &height) {
    int size = height.size();
    int res = 0;

    if (size <= 2)
      return res;

    vector<int> left_to_right(size), right_to_left(size);

    // 位置为 i 的前面最高山
    left_to_right[0] = 0;
    for (int i = 1; i < size; i++) {
      left_to_right[i] = max(left_to_right[i - 1], height[i - 1]);
    }

    // 位置为 i 的后面最高山
    right_to_left[size - 1] = 0;
    for (int i = size - 2; i >= 0; i--) {
      right_to_left[i] = max(right_to_left[i + 1], height[i + 1]);
    }

    // 位置为 i 的蓄水量 = min（前面最高山，后面最高山） - 自己的高
    for (int i = 0; i < size; i++)
      res += max(0, min(left_to_right[i], right_to_left[i]) - height[i]);

    return res;
  }
};
