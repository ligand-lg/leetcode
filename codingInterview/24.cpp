#include "../leetcode.h"

class Solution {
  vector<vector<int>> helper(TreeNode* root, int expect) {
    // leaf node
    vector<vector<int>> result;
    if (root == nullptr) return result;
    if (root->left == nullptr && root->right == nullptr){
      if (expect == root->val)
        result.push_back(vector<int>{root->val});
      return result;
    }
    for (auto left:helper(root->left, expect - root->val)) {
      left.insert(left.begin(), root->val);
      result.push_back(left);
    }
    for (auto right:helper(root->right, expect - root->val)) {
      right.insert(right.begin(), root->val);
      result.push_back(right);
    }
    return result;
  }
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
      vector<vector<int>> result;
      if (root == nullptr) return result;
      result = helper(root, expectNumber);
      sort(result.begin(), result.end(), [](const vector<int> &a, const vector<int> &b) {
        return a.size() > b.size();
      });
      return result;
    }
};

int main() {
  cout << "hell";
  return 0;
}