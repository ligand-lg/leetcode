//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    int res = 0;
    map<int, int> hash_table;

    for (auto a:A) {
      for (auto b:B) {
        auto find = hash_table.find(a + b);
        if (find == hash_table.end())
          hash_table[a + b] = 1;
        else
          hash_table[a + b] = find->second + 1;
      }
    }

    for (auto c:C) {
      for (auto d:D) {
        auto find = hash_table.find(0 - c - d);
        if (find != hash_table.end())
          res += find->second;
      }
    }

    return res;
  }
};
