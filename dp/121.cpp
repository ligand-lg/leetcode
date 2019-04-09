#include "leetcode.h"

/*
 * 转移方程: f(n) = max(f(n-1), a[n] - min(a[1...n]))  ( n = [1...n] );
 *          f(n) = 0 ( n <= 0 );
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }
    int result = 0;
    int max_before, i;
    max_before = prices[prices.size() - 1];
    for (i = prices.size() - 2; i >= 0; --i) {
      result = max(result, (max_before - prices[i]));
      max_before = max(max_before, prices[i]);
    }
    return result;
  }
};

int main() {
  Solution t;
  vector<int> test_data = {4, 1, 2, 8};
  cout << t.maxProfit(test_data);
  return 0;
}