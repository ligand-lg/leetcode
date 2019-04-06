#include "leetcode.h"
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int result, buy_day, today, the_size;
    result = 0;
    buy_day = 0;
    the_size = prices.size();
    for (today = 1; today < the_size; ++today) {
      if (prices[today] < prices[today-1]) {
        // sell 
        result += prices[today - 1] - prices[buy_day];
        buy_day = today;
      }
    }
    result += prices[the_size-1] - prices[buy_day];
    return result;
  }
};