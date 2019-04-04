#include "leetcode.h"
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
  vector<int> test_data = { 4,1, 2, 8};
  cout << t.maxProfit(test_data);
  return 0;
}