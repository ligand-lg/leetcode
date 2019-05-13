//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include <string>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int hash_table[26];
    memset(hash_table, 0, sizeof(int) * 26);

    for (auto c:s)
      hash_table[c - 'a']++;

    for (int i = 0; i < s.size(); i++)
      if (hash_table[s[i] - 'a'] == 1)
        return i;

    return -1;

  }
};
