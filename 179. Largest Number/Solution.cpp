//
// Created by fry on 2019-05-25
//

/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    if (nums.empty())
      return "";

    vector<string> strs(nums.size());
    for (int i = 0; i < strs.size(); ++i) {
      strs[i] = to_string(nums[i]);
    }

    sort(strs.begin(), strs.end(), [](const auto &a, const auto &b) -> bool {
      return (a + b) > (b + a);
    });

    if (strs[0][0] == '0')
      return "0";

    string res;
    for (auto s:strs) {
      res += s;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> test_case = {121, 12};
  cout << s.largestNumber(test_case) << endl;
}
