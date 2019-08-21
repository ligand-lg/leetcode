#include "../leetcode.h"

class Solution {
public:
     int  NumberOf1(int n) {
       unsigned int flag = 1;
       int cnt = 0;
       while (flag != 0) {
         cnt += (flag & n) == 0 ? 0: 1;
         flag = flag << 1;
       }
       return cnt;
     }
};

int main() {
  Solution s;
  cout << s.NumberOf1(-1);
  return 0;
}