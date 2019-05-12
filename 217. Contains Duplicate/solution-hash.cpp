//
// Created by ligand on 2019-05-12.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> hash_table(nums.begin(), nums.end());
    return nums.size() > hash_table.size();
  }
};
