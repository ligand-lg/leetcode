/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
  void aux(TreeNode *root, vector<string> &res, string &tmp) {
    // leaf node
    if (root->left == nullptr && root->right == nullptr) {
      tmp += to_string(root->val);
      res.push_back(tmp);
      return;
    }
    tmp += to_string(root->val);
    tmp += "->";
    if (root->right != nullptr) {
      string tmp2(tmp);
      aux(root->right, res, tmp2);
    }

    if (root->left != nullptr)
      aux(root->left, res, tmp);
  }
 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<string> res;
    string tmp;
    aux(root, res, tmp);
    return res;
  }
};
int main() {
  Solution s;
  for (auto &s : s.binaryTreePaths(Utils::str_to_tree("[1,2,3,null,5]"))) {
    cout << s << endl;
  }
}
