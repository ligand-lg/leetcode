//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n k log(k))
 * S(n) = O(nk)
 */

#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> hash_table;

    for (auto &s:strs) {
      string key(s);
      sort(key.begin(), key.end());
      if (hash_table.find(key) == hash_table.end())
        hash_table[key] = vector<string>{s};
      else
        hash_table[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &item: hash_table)
      res.push_back(item.second);

    return res;
  }
};
