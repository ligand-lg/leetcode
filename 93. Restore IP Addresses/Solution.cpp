/**
 *
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<string> restoreIpAddresses(const string &s) {
    const int size = s.size();
    if (size < 2 || size > 12)
      return vector<string>();
    vector<string> res;
    int i = 0;
    int a = stoi(s.substr(0, i + 1));
    while (a <= 255 && i < size - 3) {
      int j = i + 1;
      int b = stoi(s.substr(i + 1, j - i));
      while (b <= 255 && j < size - 2) {
        int k = j + 1;
        int c = stoi(s.substr(j + 1, k - j));
        while (c <= 255 && k < size - 1) {
          int d = stoi(s.substr(k + 1, size - k));
          if ((s[k + 1] == '0' && (size - k == 2)) || (s[k + 1] != '0' && d <= 255)) {
            // one case
            res.emplace_back(to_string(a) + '.' + to_string(b) + '.' + to_string(c) + '.' + to_string(d));
          }
          // update c
          if (s[j + 1] == '0')
            break;
          ++k;
          c = stoi(s.substr(j + 1, k - j));
        }
        // update b
        if (s[i + 1] == '0')
          break;
        ++j;
        b = stoi(s.substr(i + 1, j - i));
      }

      // update a
      if (s[0] == '0')
        break;
      ++i;
      a = stoi(s.substr(0, i + 1));
    }
    return res;
  }
};

