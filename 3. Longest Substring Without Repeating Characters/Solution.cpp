//
// Created by ligand on 2019-05-11.
//

/**
 * tag: # hash table # # sliding window #
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <string>
#include <map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if (size == 0)
      return 0;

    map<char, int> hash_table;
    int sub_start_index = 0, max_sub_len = 0, cur_sub_len = 0;

    for (int i = 0; i < size; i++) {
      auto find = hash_table.find(s[i]);
      if (find != hash_table.end() && find->second >= sub_start_index) {
        // find
        cur_sub_len = i - sub_start_index;
        if (cur_sub_len > max_sub_len)
          max_sub_len = cur_sub_len;
        sub_start_index = find->second + 1;
      }
      hash_table[s[i]] = i;
    }
    // 擦屁股
    cur_sub_len = size - sub_start_index;
    if (cur_sub_len > max_sub_len)
      max_sub_len = cur_sub_len;

    return max_sub_len;
  }
};
