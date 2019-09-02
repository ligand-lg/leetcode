#include "../leetcode.h"
class Solution {
public:
    int MoreThanHalfNum_Solution(const vector<int> &numbers) {
      // 第一步找出预选值
      int ans = 0;
      int times = 0;
      for (auto n : numbers) {
        if (ans == n){
          ++times;
        }
        else {
         --times;
         if (times <= 0) {
           ans = n;
           times = 1;
         }
        }
      }
      // 第一步校验预选值
      times = 0;
      for (auto n : numbers) {
        times += n == ans ? 1 : 0;
      }
      return (times * 2 > numbers.size()) ? ans : 0;
    }
};

int main() {
  Solution s;
  cout << s.MoreThanHalfNum_Solution(vector<int>{1, 2, 3, 4, 8, 8, 8, 8, 8});
}
