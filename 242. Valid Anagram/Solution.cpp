//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(m+n)
 * S(n) = O(1)
 */

#include <string>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    const int HashTableSize = 26;
    int hash_table[HashTableSize];
    memset(hash_table, 0, sizeof(int) * HashTableSize);

    for (auto c:s)
      hash_table[c - 'a'] += 1;
    for (auto c:t)
      hash_table[c - 'a'] -= 1;
    for (auto h:hash_table) {
      if (h != 0)
        return false;
    }
    return true;
  }
};
