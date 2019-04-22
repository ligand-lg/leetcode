//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  string LeftRotateString(string str, int n) {
    if (n <= 0 || str.empty()) return str;
    int size = str.size();
    n %= size;
    string result(str.begin() + n, str.end());
    result += string(str.begin(), str.begin() + n);
    return result;
  }
};

int main() {
  Solution s;
  cout << s.LeftRotateString("8", 8);
  return 0;
}
