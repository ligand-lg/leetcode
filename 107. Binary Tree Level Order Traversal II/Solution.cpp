/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;
    queue<pair<TreeNode *, int>> que;
    que.emplace(root, 0);
    int now_level = 0;
    vector<int> tmp;
    while (!que.empty()) {
      auto node = que.front().first;
      auto level = que.front().second;
      que.pop();
      if (level != now_level) {
        res.push_back(tmp);
        tmp.clear();
        now_level = level;
      }
      tmp.push_back(node->val);
      if (node->left)
        que.emplace(node->left, level + 1);
      if (node->right)
        que.emplace(node->right, level + 1);
    }
    if (!tmp.empty())
      res.push_back(tmp);
    reverse(res.begin(), res.end());
    return res;
  }
};

