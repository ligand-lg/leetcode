//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
  string result;
  void reverse(int start, int end) {
    char tmp;
    while (start < end) {
      tmp = result[start];
      result[start] = result[end];
      result[end] = tmp;
      start++;
      end--;
    }
  }
 public:
  string ReverseSentence(string str) {
    this->result = str;
    reverse(0, str.size() - 1);
    int end;
    int i = 0;
    while (i < str.size()) {
      for (end = i; end < result.size() && result[end] != ' '; end++);
      reverse(i, end - 1);
      i = end + 1;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.ReverseSentence("");
  return 0;
}
