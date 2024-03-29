#include "../leetcode.h"

class Solution {
public:
  int nthUglyNumber(int n) {
    queue<int> q1, q2, q3;
    q1.push(2);
    q2.push(3);
    q3.push(5);

    int res = 1;
    for (size_t i = 1; i < n; ++i) {
      res = min({q1.front(), q2.front(), q3.front()});
      if (q1.front() == res) {
        q1.pop();
      }
      if (q2.front() == res) {
        q2.pop();
      }
      if (q3.front() == res) {
        q3.pop();
      }
      q1.push(2 * res);
      q2.push(3 * res);
      q3.push(5 * res);
    }
    return res;
  }
};