/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return root;
    queue<Node *> tmp;
    tmp.push(root);
    tmp.push(nullptr);
    while (!tmp.empty()) {
      auto next = tmp.front();
      tmp.pop();
      if (next == nullptr) {
        if (!tmp.empty()) {
          tmp.push(nullptr);
        }
      } else {
        next->next = tmp.front();
        if (next->left != nullptr) {
          tmp.push(next->left);
        }
        if (next->right != nullptr) {
          tmp.push(next->right);
        }
      }
    }
    return root;
  }
};
