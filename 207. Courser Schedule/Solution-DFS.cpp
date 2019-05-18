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
  bool is_cycling_dfs(int v, vector<bool> &done, const vector<vector<int>> &adj_list, vector<bool> &tmp) {
    // 出口一：到达本次dfs之前访问过的节点，有环。
    if (tmp[v])
      return true;

    // 出口二：到达已经证明清白的节点，无环。
    if (done[v])
      return false;

    tmp[v] = true;
    for (auto next_v:adj_list[v])
      if (is_cycling_dfs(next_v, done, adj_list, tmp))
        return true;

    tmp[v] = false;
    done[v] = true;

    // 出口三：无环
    return false;
  }
 public:
// 有向图判环
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses < 2)
      return true;

    vector<vector<int>> adj_list(numCourses, vector<int>());
    for (auto pre:prerequisites) {
      // pre[1] -> pre[0]
      adj_list[pre[1]].push_back(pre[0]);
    }

    // 记录已经清白的节点
    vector<bool> done(numCourses, false);
    // 一次 dfs 的缓存
    vector<bool> once_tmp(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
      if (!done[i] && is_cycling_dfs(i, done, adj_list, once_tmp))
        return false;
    }
    return true;
  }
};

