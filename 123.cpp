#include "leetcode.h"

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int count = prices.size();
    if (count < 2) return 0;

    // left to right
    int *left_to_right = new int[count];
    int i = 0;
    left_to_right[i++] = 0;
    int min_value = prices[0];
    for (; i < count; i++) {
      left_to_right[i] = max(left_to_right[i-1], prices[i] - min_value);
      min_value = min(min_value, prices[i]);
    }

    // right to left
    int *right_to_left = new int[count];
    i = count - 1;
    right_to_left[i--] = 0;
    int max_value = prices[count-1];
    for (; i > 0; i--) {
      right_to_left[i] = max(right_to_left[i-1], max_value - prices[i]);
      max_value = max(max_value, prices[i]);
    }


    int result = 0;
    // k
    for(int k = 0; k < count; k++) {
      result = max(result, left_to_right[k] + right_to_left[k]);
    }
    return result;
  }
};