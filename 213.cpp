#include "leetcode.h"

/* 
 * 1. 同198题，转移方程: f(n) = max(f(n-1), f(n-2) + a[n]) （ 1 < n < n )
 * 2. 两条线对应两中不同初始条件。
 *      抢 1 号屋： f(N) = f(N-1) （不能再抢N号屋）
 *      不抢 1 号屋：f(N) = max(f(N-1), f(N-2) + a[N]
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int rob(vector<int>& nums) {
    int count = nums.size();
    int result = 0;

    if (count < 4) {
      for (int i = 0; i < count; i++) {
        result = max(result, nums[i]);
      }
      return result;
    }

    // N >= 4
    // without rob 1;
    int end = count - 1;
    int tmp = 0;
    int f_n_1, f_n_2;
    f_n_1 = 0;
    f_n_2 = 0;
    for (int i = 1; i < end; i++) {
      tmp = max(f_n_1, f_n_2 + nums[i]);
      f_n_2 = f_n_1;
      f_n_1 = tmp;
    }
    result = max(f_n_1, f_n_2 + nums[count - 1]);

    // with rob 1;
    int f_n_1_r1, f_n_2_r1;
    f_n_1_r1 = nums[0];
    f_n_2_r1 = 0;
    for (int i = 1; i < end; i++) {
      tmp = max(f_n_1_r1, f_n_2_r1 + nums[i]);
      f_n_2_r1 = f_n_1_r1;
      f_n_1_r1 = tmp;
    }
    result = max(result, f_n_1_r1);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> data{1, 2, 3, 1};
  cout << s.rob(data);
  return 0;
}
