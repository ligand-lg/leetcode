#include "../leetcode.h"

/*
 * 转移方程: f(n) = f(n-1) + (f(n-2) if a[n-1...n] <= 26), n > 1
 * 初始值:   f(1) = 1, f(0) = 1;
 *
 * T(n) = O(n)，其中 n 为目标字符串长度，m 为字典元素个数;
 * S(n) = O(n);
 */

class Solution {
  vector<int> dp;
  string a;
  int helper(int n) {
    // 初始条件dp[0] = 1, dp[1] = 1，已经在数组中
    if (dp[n] < 0) {
      if (a[n - 1] == '0')
        dp[n] = helper(n - 1);
      else {
        dp[n] = helper(n - 1) +
                ((a[n - 2] == '1' || (a[n - 2] == '2' && a[n - 1] < '7'))
                     ? helper(n - 2)
                     : 0);
      }
    }
    return dp[n];
  }

 public:
  int numDecodings(string s) {
    // all zero case
    auto it = s.begin();
    while (*it == '0' && it != s.end()) it++;
    if (it == s.end()) return 0;
    a = s;
    dp = vector<int>(s.length() + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return helper(s.length());
  }
};

int main() {
  Solution s;
  cout << s.numDecodings("01");
  return 0;
}