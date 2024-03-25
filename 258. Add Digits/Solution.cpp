#include "../leetcode.h"

class Solution {
public:
  int addDigits(int num) {
    int n = num;
    while (n > 9) {
      int newN = 0;
      while (n > 0) {
        int times = n / 10;
        int left = n - (times * 10);
        newN += left;
        n = times;
      }
      n = newN;
    }
    return n;
  }
};

int main() {
  Solution s;
  int res = s.addDigits(8);
  cout << res;
}