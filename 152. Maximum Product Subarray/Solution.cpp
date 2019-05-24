//
// Created by fry on 2019-05-24
//

/**
 * 转移方程: f(n) = max(a[n], a[n] * f(n-1))
 * 初始值:   f(0) = a[0]
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    int res = nums[0];
    int min_num = res, max_num = res;

    int n;
    for (int i = 1; i < nums.size(); ++i) {
      n = nums[i];
      if (n < 0)
        swap(min_num, max_num);
      max_num = max(max_num * n, n);
      min_num = min(min_num * n, n);
      res = max(max_num, res);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> test_case = {2, 3, -2, 4};
  cout << s.maxProduct(test_case);
}
