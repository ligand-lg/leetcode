#include "../leetcode.h"

/*
 * 转移方程: f(s, e) = root: i, left: f(s, i-1), right: f(i+1, e), i = [s...e],s
 * <= e 初始值:   f(s,e) = [NULL], s > e
 *
 * T(n) = O(n^2)
 * S(n) = O(n);
 */

class Solution {
  map<pair<int, int>, vector<TreeNode*>> dp;
  vector<TreeNode*> helper(int start, int end) {
    if (start > end || end < 1) return vector<TreeNode*>(1, NULL);
    vector<TreeNode*> result;
    auto find = dp.find(pair<int, int>(start, end));
    if (find == dp.end()) {
      for (int i = start; i <= end; ++i) {
        for (auto left : helper(start, i - 1)) {
          for (auto right : helper(i + 1, end)) {
            TreeNode* h = new TreeNode(i);
            h->left = left;
            h->right = right;
            result.push_back(h);
          }
        }
      }
      dp[pair<int, int>(start, end)] = result;
    } else {
      result = find->second;
    }
    return result;
  }

 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n < 1) return vector<TreeNode*>();
    for (int i = 1; i <= n; i++) {
      dp[pair<int, int>(i, i)] = vector<TreeNode*>(1, new TreeNode(i));
    }
    return helper(1, n);
  }
};

int main() {
  Solution s;
  s.generateTrees(3);
  return 0;
}