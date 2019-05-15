//
// Created by ligand on 2019-05-15.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> left_to_right;
    queue<TreeNode *> right_to_left;
    vector<vector<int>> res;

    left_to_right.push(root);
    TreeNode *node;
    while (!left_to_right.empty()) {
      vector<int> line;

      while (!left_to_right.empty()) {
        node = left_to_right.front();
        left_to_right.pop();
        if (node != nullptr) {
          line.push_back(node->val);
          right_to_left.push(node->left);
          right_to_left.push(node->right);
        }
      }
      if (!line.empty())
        res.push_back(line);

      line.clear();
      while (!right_to_left.empty()) {
        node = right_to_left.front();
        right_to_left.pop();
        if (node != nullptr) {
          line.push_back(node->val);
          left_to_right.push(node->left);
          left_to_right.push(node->right);
        }
      }
      if (!line.empty())
        res.push_back(line);
    }
    for (int i = 1; i < res.size(); i+=2) {
      reverse(res[i].begin(), res[i].end());
    }
    return res;
  }
};

int main() {
  Solution s;
  TreeNode root(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, nullptr, new TreeNode(5)));
  auto r = s.zigzagLevelOrder(&root);
  return 0;
}
