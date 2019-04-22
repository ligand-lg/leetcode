#include "../leetcode.h"

class Solution {
 public:
  string PrintMinNumber(vector<int> numbers) {
    // iota
    vector<string> strs;
    for (auto n : numbers) {
      string s;
      while (n != 0) {
        s.insert(s.begin(), n % 10 + '0');
        n = n / 10;
      }
      strs.push_back(s);
    }
    sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
      string c1 = s1 + s2;
      string c2 = s2 + s1;
      return c1 < c2;
    });
    string result;
    for (auto s : strs) {
      result += s;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.PrintMinNumber(vector<int>());
  return 0;
}