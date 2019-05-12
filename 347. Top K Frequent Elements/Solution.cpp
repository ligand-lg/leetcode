//
// Created by ligand on 2019-05-11.
//

/**
 * tag: # hash table # # heap #
 * T(n) = O(n log(k))
 * S(n) = O(n)
 *
 */

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // 1. hash table counter
    // <n, count>
    map<int, int> hash_table;
    for (auto n : nums) {
      auto find = hash_table.find(n);
      if (find != hash_table.end()) {
        // find
        hash_table[n] += 1;
      }else {
        // not find
        hash_table[n] = 1;
      }
    }

    // 2. heap sort ( 最小堆 )
    priority_queue<pair<int, int>> heap;


  }
};
