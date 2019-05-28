//
// Created by fry on 2019-05-28
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int numSquares(int n) {
    if (n <= 0)
      return 0;

    static vector<int> perfectSquares = {1};
    static vector<int> cntPerfectSquares = {0};

    while (perfectSquares.size() * perfectSquares.size() <= n) {
      perfectSquares.push_back((perfectSquares.size()+1) * (perfectSquares.size()+1));
    }

    while (cntPerfectSquares.size() <= n) {
      int m = cntPerfectSquares.size();
      int initCnt = INT_MAX;
      for (int i = 0; perfectSquares[i] <= m; ++i) {
        initCnt = min(initCnt, cntPerfectSquares[m - perfectSquares[i]] + 1);
      }
      cntPerfectSquares.push_back(initCnt);
    }
    return cntPerfectSquares[n];
  }
};

int main() {
  Solution s;
  cout << s.numSquares(13);
}
