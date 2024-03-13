#include "../leetcode.h"

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
      res = max(res, nums[i] - nums[i - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> d{1, 1000};
  int res = s.maximumGap(d);
  cout << res;
}