#include "../leetcode.h"

class Solution {
 public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() == 0 || k <= 0 || k > input.size()) return vector<int>();

    priority_queue<int> result;
    for (auto ele : input) {
      if (result.size() < k) {
        result.push(ele);
        continue;
      }
      if (ele < result.top()) {
        result.pop();
        result.push(ele);
      }
    }
    vector<int> result_vec;
    while (!result.empty()) {
      result_vec.push_back(result.top());
      result.pop();
    }
    return result_vec;
  }
};

int main() {
  Solution s;
  for (auto s : s.GetLeastNumbers_Solution(vector<int>{1, 8, 9, 4, 2, 3}, 4)) {
    cout << s;
  }
  return 0;
}