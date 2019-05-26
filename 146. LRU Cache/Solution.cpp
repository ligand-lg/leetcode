//
// Created by fry on 2019-05-26
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class LRUCache {
  int cap;
  // 使用双链表来实现LRU记录
  list<int> lru;
  // 使用辅助 hash table 来实现LRU记录
  unordered_map<int, list<int>::iterator> ki;

  unordered_map<int, int> kv;

  // 更新 key 到最新
  void updateLRU(int key) {
    if (kv.count(key))
      lru.erase(ki[key]);
    lru.push_front(key);
    ki[key] = lru.begin();
  }

  // 置换一个位置出来
  void evict() {
    ki.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
  }

 public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (kv.count(key) == 0) return -1;
    updateLRU(key);
    return kv[key];
  }

  void put(int key, int val) {
    if (kv.size() == cap && kv.count(key) == 0)
      evict();
    updateLRU(key);
    kv[key] = val;
  }
};
