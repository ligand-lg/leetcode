#include "../leetcode.h"

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.length() < t.length()) {
      return "";
    }
    vector<int> cnts(128, 0);

    for (auto c : t) {
      cnts[c]++;
    }

    size_t start = 0, end = 0, minLen = SIZE_MAX, minStart;
    size_t count = t.length();
    while (end < s.length()) {
      if (cnts[s[end++]]-- > 0) {
        count--;
      }

      while (count == 0) {
        if (end - start < minLen) {
          minLen = end - start;
          minStart = start;
        }
        if (cnts[s[start++]]++ == 0) {
          count++;
        }
      }
    }

    return minLen == SIZE_MAX ? "" : s.substr(minStart, minLen);
  }
};

int main() {
  Solution s;
  string res = s.minWindow("AB", "A");
  cout << res;
}