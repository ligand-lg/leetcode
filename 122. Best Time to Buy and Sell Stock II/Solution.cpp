//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    int size = prices.size();

    int buy_day = 0;
    // 第 buy_day 天买入
    while (buy_day < size) {
      int sell_day = buy_day + 1;
      while (sell_day < size && prices[sell_day] >= prices[sell_day - 1])
        sell_day++;
      sell_day--;
      // 一次交易，第 buy_day 天买，第 sell_day 天卖
      if (prices[sell_day] > prices[buy_day])
        res += prices[sell_day] - prices[buy_day];
      buy_day = sell_day + 1;
    }
    return res;
  }
};

