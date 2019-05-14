//
// Created by ligand on 2019-05-14.
//

/**
 * 转移方程: f(n) = max(f(n-1), n - min([1,n])
 * 初始值:   f(1) = 0
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &nums) {
    int res = 0;
    if (nums.empty())
      return res;

    int buy_price = nums[0];
    const int size = nums.size();
    for (int i = 1; i < size; i++) {
      res = max(res, nums[i] - buy_price);
      buy_price = min(buy_price, nums[i]);
    }
    return res;
  }

};
