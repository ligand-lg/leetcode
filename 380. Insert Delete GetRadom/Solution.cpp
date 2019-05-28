//
// Created by fry on 2019-05-28
//

/**
 *
 * T(n) = O(1)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class RandomizedSet {
  // value -> index
  unordered_map<int, int> hash_table;
  // index - value
  vector<int> nums;
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (hash_table.find(val) != hash_table.end())
      return false;
    nums.push_back(val);
    hash_table[val] = nums.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (hash_table.find(val) == hash_table.end())
      return false;
    // 将最后一个元素换个 val 的位置
    nums[hash_table[val]] = nums.back();
    hash_table[nums.back()] = hash_table[val];
    nums.pop_back();
    hash_table.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums[rand() % nums.size()];
  }
};

