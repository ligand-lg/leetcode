#include <vector>
#include <iostream>
using namespace std;
#ifndef NULL
#define NULL 0
#endif

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
