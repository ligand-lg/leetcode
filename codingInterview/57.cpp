//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  // 找到根为root的树中，中序遍历的第一个元素，找不到返回nullptr
  TreeLinkNode *helper(TreeLinkNode *root) {
    if (root == nullptr)
      return nullptr;
    while (root->left != nullptr)
      root = root->left;
    return root;
  }

 public:
  TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    if (pNode == nullptr)
      return nullptr;
    if (pNode->right != nullptr)
      return helper(pNode->right);
    while(pNode->next != nullptr && pNode->next->left != pNode){
      pNode = pNode->next;
    }
    return pNode->next;
  }
};


int main() {
  Solution s;
  s.GetNext();
  return 0;
}
