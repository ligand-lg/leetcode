//
// Created by fry on 2019-05-18
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n^2)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses < 2)
      return true;

    // 邻接表 表示边
    vector<vector<int>> adj_list(numCourses, vector<int>());
    // 各顶点入度
    vector<int> in_degree(numCourses, 0);

    // 初始化 邻接矩阵 和 各顶点入度
    for (auto pre:prerequisites) {
      // pre[1] -> pre[0]
      adj_list[pre[1]].push_back(pre[0]);
      in_degree[pre[0]]++;
    }

    queue<int> zero_in_degree;
    // 已经修的课程数
    int cnt = 0;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0)
        zero_in_degree.push(i);
    }
    while (!zero_in_degree.empty()) {
      int v = zero_in_degree.front();
      zero_in_degree.pop();
      cnt += 1;

      for (auto next_v : adj_list[v]) {
        in_degree[next_v]--;
        if (in_degree[next_v] == 0)
          zero_in_degree.push(next_v);
      }
    }
    return cnt == numCourses;
  }
};
