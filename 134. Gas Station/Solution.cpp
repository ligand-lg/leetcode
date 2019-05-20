//
// Created by fry on 2019-05-20
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = gas.size() - 1;
    int end = 0;
    int sum = gas[start] - cost[start];
    while (start > end) {
      if (sum >= 0) {
        sum += gas[end] - cost[end];
        end++;
      } else {
        start--;
        sum += gas[start] - cost[start];
      }
    }
    return sum < 0 ? -1 : start;
  }
};
