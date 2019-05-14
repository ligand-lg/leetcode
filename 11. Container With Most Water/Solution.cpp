//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &heights) {
    int i = 0, j = heights.size() - 1, k;
    int res = 0;

    while (i < j) {
      res = max(res, min(heights[i], heights[j]) * (j - i));
      if (heights[i] < heights[j]) {
        for (k = i + 1; k < j && heights[k] <= heights[i]; k++);
        i = k;
      } else {
        for (k = j - 1; k > i && heights[k] <= heights[j]; k--);
        j = k;
      }
    }

    return res;
  }
};
