//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  int Sum_Solution(int n) {
    int result = n;
    result && (result += Sum_Solution(n - 1));
    return result;
  }
};
