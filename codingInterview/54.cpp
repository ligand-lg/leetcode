//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
  int mark[255] = {0};
  queue<char> data;
 public:
  //Insert one char from stringstream
  void Insert(char ch) {
    if (mark[ch] < 2) {
      data.push(ch);
      mark[ch] += 1;
    }
  }
  //return the first appearence once char in current stringstream
  char FirstAppearingOnce() {
    char res = '#';
    while (!data.empty() && mark[data.front()] > 1)
      data.pop();
    if (!data.empty()) {
      res = data.front();
    }
    return res;
  }
};
