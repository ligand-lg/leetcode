#include "../leetcode.h"

class Solution {
  vector<string> help(const string &str, int index) {
    if (index < 0)
      return {""};
    vector<string> ans;
    auto pre_ans = help(str, index-1);
    for (auto s : pre_ans) {
      for (int i = 0; i <= s.length(); ++i) {
        s.insert(s.begin() + i, str[index]);
        ans.push_back(s);
        s.erase(s.begin() + i);
      }
    }
    return ans;
  }
public:
    vector<string> Permutation(string str) {
      if (str.length() == 0) return {};
      auto _ans = help(str, str.length() - 1);
      set<string> set_ans(_ans.begin(), _ans.end());
      return vector<string>(set_ans.begin(), set_ans.end());
    }
};

int main() {
  Solution s;
  for (auto str : s.Permutation("ab")) {
    cout << str << endl;
  }
  return 0;
}
