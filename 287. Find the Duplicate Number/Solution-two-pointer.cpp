//
// Created by fry on 2019-05-26
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    int tortoise = nums[0];
    int hare = nums[0];
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    int ptr1 = nums[0];
    int ptr2 = hare;
    while (ptr1 != ptr2) {
      ptr1 = nums[ptr1];
      ptr2 = nums[ptr2];
    }
    return ptr1;
  }
};
