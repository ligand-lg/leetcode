//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  bool IsContinuous(vector<int> numbers) {
    if (numbers.empty()) return false;
    vector<int> hash(14, 0);
    for (auto n: numbers) hash[n] += 1;
    int first, last;
    first = 1;
    while (first < 14 && hash[first] == 0) first++;
    last = 13;
    while (last >= first && hash[last] == 0) last--;
    while (first <= last) {
      if (hash[first] > 1)
        return false;
      else if (hash[first] == 0)
        hash[0] -= 1;
      first++;
    }
    return hash[0] >= 0;
  }
};

int main() {
  Solution s;
  cout << s.IsContinuous(vector<int>{3, 0, 0, 0, 0});
}
