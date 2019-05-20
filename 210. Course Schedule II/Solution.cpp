//
// Created by fry on 2019-05-20
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj_list(numCourses, vector<int>());
    vector<int> res(numCourses, 0);
    vector<int> in_degree(numCourses, 0);

    // init adj_list
    for (auto pi:prerequisites) {
      adj_list[pi[1]].push_back(pi[0]);
      in_degree[pi[0]]++;
    }

    queue<int> zero_degree;
    int cnt = 0;
    // init zero_degree
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0)
        zero_degree.push(i);
    }

    while (!zero_degree.empty()) {
      int node = zero_degree.front();
      zero_degree.pop();
      res[cnt++] = node;

      for (auto i : adj_list[node]) {
        in_degree[i]--;
        if (in_degree[i] == 0)
          zero_degree.push(i);
      }
    }

    // 没有遍历完，有环，返回空
    if (cnt != numCourses)
      res = vector<int>();

    return res;
  }
};
