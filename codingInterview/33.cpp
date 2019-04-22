#include "../leetcode.h"

class Solution {
 public:
  int GetUglyNumber_Solution(int index) {
    if (index <= 0) return 0;
    int cur = 1;
    vector<int> tmp{1};
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    for (int i = 1; i < index; i++) {
      while ((tmp[i2] * 2) <= cur) i2++;
      while ((tmp[i3] * 3) <= cur) i3++;
      while ((tmp[i5] * 5) <= cur) i5++;
      cur = min(tmp[i2] * 2, min(tmp[i3] * 3, tmp[i5] * 5));
      tmp.push_back(cur);
    }
    return cur;
  }
};

int main() {
  Solution s;
  cout << s.GetUglyNumber_Solution(1500);
  return 0;
}