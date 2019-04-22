//
// Created by ligand on 2019-04-22.
//
#include "../leetcode.h"

class Solution {
 public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> result;
    int s_i, e_i;
    s_i = 0;
    e_i = array.size() - 1;
    while (s_i < e_i && array[s_i] + array[e_i] != sum) {
      if (array[s_i] + array[e_i] > sum)
        e_i--;
      else
        s_i++;
    }
    if (s_i < e_i) {
      result.push_back(array[s_i]);
      result.push_back(array[e_i]);
    }
    return result;
  }
};
