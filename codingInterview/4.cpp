#include "../leetcode.h"

class Solution {
  vector<int> pre;
  vector<int> vin;
  TreeNode* helper(int pre_begin, int vin_begin, int len) {
    if (len <= 0) return nullptr;
    int root_val = pre[pre_begin];
    int root_in_vin = vin_begin;
    int vin_end = vin_begin + len;
    for (; root_in_vin <= vin_end; root_in_vin++) {
      if (vin[root_in_vin] == root_val) break;
    }
    if (root_in_vin > vin_end) {
      cout << "root value not in vin" << root_val << endl;
      return nullptr;
    }
    int left_len = root_in_vin - vin_begin;
    TreeNode* root = new TreeNode(root_val);
    root->left = helper(pre_begin + 1, vin_begin, left_len);
    root->right =
        helper(pre_begin + left_len + 1, root_in_vin + 1, len - left_len - 1);
    return root;
  }

 public:
  TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    this->pre = pre;
    this->vin = vin;
    return helper(0, 0, pre.size());
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