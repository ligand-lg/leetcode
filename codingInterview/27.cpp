#include "../leetcode.h"

class Solution {
  vector<string> helper(string str) {
    if (str.length() == 0) return vector<string>(1, "");
    vector<string> result;
    int end = str.length();
    for (int i = 0; i < end; i++) {
      char cur = str[i];
      str.erase(i, 1);
      for (auto r : helper(str)) {
        r.insert(r.begin(), cur);
        result.push_back(r);
      }
      str.insert(str.begin() + i, cur);
    }
    return result;
  }

 public:
  vector<string> Permutation(string str) {
    if (str.length() == 0) return vector<string>();
    sort(str.begin(), str.end());
    auto result_v = helper(str);
    auto result_s = set<string>(result_v.begin(), result_v.end());
    return vector<string>(result_s.begin(), result_s.end());
  }
};

int main() {
  Solution s;
  for (auto str : s.Permutation("cccc")) {
    cout << str << endl;
  }
  return 0;
}