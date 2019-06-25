/**
 * 转移方程: f(n) = f(n-1)*(a!=0) + f(n-2) * ( 9 < a[n-1]a[n] < 27)
 * 初始值:  f(0) = 0, f(1) = (a != 0)
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int numDecodings(const string &s) {
    if (s.empty() || s[0] == '0') return 0;
    const int size = s.size();
    if (size == 1) return 1;
    auto dp = new int[size + 1];
    dp[0] = 0;
    dp[1] = 1;
    // 单独两位需要特殊处理
    dp[2] = 0;
    dp[2] += s[1] == '0' ? 0 : 1;
    if (s[0] == '1' || (s[0] == '2' && s[1] < '7'))
      dp[2] += 1;

    for (int i = 2; i < size; ++i) {
      int tmp = 0;
      // f(n) = f(n-1)*(a!=0) + f(n-2) * ( 9 < a[n-1]a[n] < 27)
      tmp += s[i] == '0' ? 0 : dp[i];
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
        tmp += dp[i - 1];
      if (tmp == 0)
        return 0;
      dp[i + 1] = tmp;
    }
    int res = dp[size];
    delete[]dp;
    return res;
  }
};
int main() {
  Solution s;
  cout << s.numDecodings("226");
}
