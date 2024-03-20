#include "../leetcode.h"

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int res = 0;
    for (int i = 30; i >= 0; --i) {
      int mod = 1 << i;
      if ((left & mod) == (right & mod)) {
        res = res | (left & mod);
      } else {
        return res;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  int res = s.rangeBitwiseAnd(0, 0);
  cout << res;
}