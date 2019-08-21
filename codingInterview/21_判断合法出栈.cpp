#include "../leetcode.h"

class Solution {
public:
    bool IsPopOrder(const vector<int> &from, const vector<int> &to) {
      int from_index = 0;
      int to_index = 0;
      stack<int> s;
      while(from_index < from.size() || !s.empty()) {
        if (s.empty() || s.top() != to[to_index]) {
          if (from_index >= from.size()) return false;
          s.push(from[from_index++]);
        }else {
          s.pop();
          to_index++;
        }
      }
      return true;
    }
};

int main() {
  Solution s;
  cout << s.IsPopOrder(vector<int>{}, vector<int>{});
}