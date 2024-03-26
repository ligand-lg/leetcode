#include "../leetcode.h"

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums;
    }

    sort(nums.begin(), nums.end());
    int n = nums.size() / 3;
    vector<int> res;

    size_t cnt = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        cnt += 1;
      } else {
        if (cnt > n) {
          res.push_back(nums[i - 1]);
        }
        cnt = 1;
      }
    }
    if (cnt > n) {
      res.push_back(nums[nums.size() - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> d{3, 2, 3};
  auto res = s.majorityElement(d);
  cout << res[0];
}