#include "../leetcode.h"

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int64_t diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

    diff &= -diff;

    vecotr<int> res = {0, 0};
    for (int n : nums) {
      if (n & diff == 0) {
        res[0] ^= n;
      } else {
        res[1] ^= n;
      }
    }

    return res;
  }
};