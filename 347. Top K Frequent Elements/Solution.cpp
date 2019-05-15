//
// Created by ligand on 2019-05-15.
//

/**
 * T(n) = O(nlogk)
 * S(n) = O(n)
 */

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> cnt;

    // hash table 计数
    for (auto n : nums) {
      if (cnt.find(n) == cnt.end())
        cnt[n] = 0;
      else
        cnt[n]++;
    }

    // 最小堆统计最大 k 个元素
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    for (auto &item : cnt) {
      if (min_heap.size() < k) {
        min_heap.push(make_pair(item.second, item.first));
        continue;
      }

      // 注意 heap 中的是<元素个数，元素>, item 是 <元素，元素个数>
      if (min_heap.top().first < item.second) {
        min_heap.push(make_pair(item.second, item.first));
        min_heap.pop();
      }
    }

    // 转成数组
    vector<int> res(k);
    int i = k - 1;
    while (!min_heap.empty()) {
      res[i--] = min_heap.top().second;
      min_heap.pop();
    }

    return res;
  }
};
