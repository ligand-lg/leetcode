#include "../leetcode.h"

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
      if (index <= 0) return 0;
      int i2, i3, i5;
      i2 = i3 = i5 = 0;
      vector<int> ans(index, 0);
      ans[0] = 1;
      for (int i = 1; i < index; ++i) {
        while(ans[i2] * 2 <= ans[i-1]) ++i2;
        while(ans[i3] * 3 <= ans[i-1]) ++i3;
        while(ans[i5] * 5 <= ans[i-1]) ++i5;
        ans[i] = min(ans[i2] * 2, min(ans[i3] * 3, ans[i5] * 5));
      }
      return ans[index - 1];
    }
};

int main() {
  Solution s;
  cout << s.GetUglyNumber_Solution(1500);
  return 0;
}
