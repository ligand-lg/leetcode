/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> twoSum(const vector<int> &numbers, int target) {
    int index1 = 0;
    int index2 = numbers.size() - 1;
    int sum = numbers[index1] + numbers[index2];
    while (sum != target) {
      if (sum < target)
        ++index1;
      else
        --index2;
      sum = numbers[index1] + numbers[index2];
    }
    return vector<int>{index1+1, index2+1};
  }
};
