#include "../leetcode.h"

class Solution {
public:
  string minWindow(string s, string t) {
    // init tCharInSIdx
    map<char, queue<size_t>> tCharInSIdx;
    for (size_t i = 0; i < t.length(); ++i) {
      tCharInSIdx[t[i]] = queue<size_t>();
    }
    for (size_t i = 0; i < s.length(); ++i) {
      if (tCharInSIdx.find(s[i]) != tCharInSIdx.end()) {
        tCharInSIdx[s[i]].push(i);
      }
    }

    vector<size_t> sIdx;
    sIdx.reserve(t.length());
    for (size_t i = 0; i < t.length(); ++i) {
      if (tCharInSIdx[t[i]].empty()) {
        return "";
      }
      sIdx.push_back(tCharInSIdx[t[i]].front());
      tCharInSIdx[t[i]].pop();
    }

    size_t minWindowSize = SIZE_MAX;
    size_t minWindowStart, minWindowEnd;
    sort(sIdx.begin(), sIdx.end());
    while (!tCharInSIdx[s[sIdx[0]]].empty()) {
      size_t windowSize = sIdx.back() - sIdx.front() + 1;
      if (windowSize < minWindowSize) {
        minWindowSize = windowSize;
        minWindowStart = sIdx.front();
      }

      // start replace
      char c = s[sIdx[0]];
      sIdx[0] = tCharInSIdx[c].front();
      tCharInSIdx[c].pop();
      sort(sIdx.begin(), sIdx.end());
    }
    if (sIdx.back() - sIdx.front() + 1 < minWindowSize) {
      minWindowSize = sIdx.back() - sIdx.front() + 1;
      minWindowStart = sIdx.front();
    }

    return s.substr(minWindowStart, minWindowSize);
  }
};

int main() {
  Solution s;
  string res = s.minWindow("ADOBECODEBANC", "ABC");
  cout << res;
}