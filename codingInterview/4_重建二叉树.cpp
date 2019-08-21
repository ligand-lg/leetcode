#include "../leetcode.h"

class Solution {
  TreeNode *help(const vector<int> &pre, const vector<int> &vin, int pre_begin,
                 int vin_begin, int len) {
    if (len <= 0) return nullptr;
    int root_val = pre[pre_begin];
    int root_in_vin =
        find(vin.begin() + vin_begin, vin.end(), root_val) - vin.begin();
    int left_len = root_in_vin - vin_begin;
    auto root = new TreeNode(root_val);
    root->left = help(pre, vin, pre_begin + 1, vin_begin, left_len);
    root->right = help(pre, vin, pre_begin + 1 + left_len, root_in_vin + 1,
                       len - left_len - 1);
    return root;
  }

 public:
  TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    return help(pre, vin, 0, 0, pre.size());
  }
};

int main() {
  Solution s;
  vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};
  TreeNode *h = s.reConstructBinaryTree(pre, vin);
  cout << h->val;
  return 0;
}