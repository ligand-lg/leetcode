//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n * log(n))
 * S(n) = O(n)
 *
 */

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

  TreeNode *helper(const vector<int> &nums, int start, int end) {
    if (start > end)
      return nullptr;
    int mid = (start + end) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(nums, start, mid - 1);
    node->right = helper(nums, mid + 1, end);
    return node;
  }
 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }

};
