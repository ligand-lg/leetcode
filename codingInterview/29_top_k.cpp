#include "../leetcode.h"

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      if (input.size() < k)
        return {};
      priority_queue<int> ans(input.begin(), input.begin() + k);
      for (int i = k; i < input.size(); ++i) {
        ans.push(input[i]);
        ans.pop();
      }
      vector<int> vec_ans;
      while(!ans.empty()) {
        vec_ans.push_back(ans.top());
        ans.pop();
      }
      return vec_ans;
    }
};

int main() {
  Solution s;
  for (auto s : s.GetLeastNumbers_Solution(vector<int>{1, 8, 9, 4, 2, 3}, 4)) {
    cout << s;
  }
  return 0;
}
