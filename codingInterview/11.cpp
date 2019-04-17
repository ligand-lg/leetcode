#include "../leetcode.h"

class Solution {
 public:
  int NumberOf1(int n) {
    unsigned int un = (unsigned int) n;
    int result = 0;
    while (un != 0) {
      result += (un & 1);
      un = un >> 1;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.NumberOf1(-1);
  return 0;
}