//
// Created by ligand on 2019-05-11.
//

/**
 * tag: # hash table #
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int size = nums.size();
    map<int, int> hash_table;
    for (int i = 0; i < size; i++) {
      int left = target - nums[i];
      auto find = hash_table.find(left);
      if (find == hash_table.end()) {
        // not find
        hash_table[nums[i]] = i;
      } else {
        //find
        return vector<int>{find->second, i};
      }
    }
    return vector<int>{-1, -1};
  }
};
