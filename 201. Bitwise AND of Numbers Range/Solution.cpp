#include "../leetcode.h"

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int res = left;
    for (size_t i = left + 1; i <= right; ++i) {
      res &= i;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.rangeBitwiseAnd(1, 2147483647);
}