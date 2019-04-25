//
// Created by ligand on 2019-04-25.
//

#include "../leetcode.h"

class Solution {
  vector<char> ser_data;
  char *des_str;
  char _nullprt = '$';
  char _sepa = ',';

  void _ser(TreeNode *root) {
    if (root == nullptr) {
      ser_data.push_back(_nullprt);
      ser_data.push_back(_sepa);
      return;
    }
    for (char c: to_string(root->val)) {
      ser_data.push_back(c);
    }
    ser_data.push_back(_sepa);
    _ser(root->left);
    _ser(root->right);
  }
  TreeNode *_des() {
    if (*des_str == '\0')
      throw "_des: 输入的字符串不是合法的树，字符串没有封闭";
    if (*des_str == _nullprt) {
      des_str += 2;
      return nullptr;
    }

    char *end = des_str;
    while (*end != _sepa) end++;
    int length = end - des_str;
    char *tmp = new char[length + 1];
    for (int i = 0; i < length; i++) {
      tmp[i] = *(des_str + i);
    }
    tmp[length] = '\0';
    int val = atoi(tmp);
    delete[]tmp;
    des_str = end + 1;

    auto root = new TreeNode(val);
    root->left = _des();
    root->right = _des();
    return root;
  }
 public:
  char *Serialize(TreeNode *root) {
    ser_data.clear();
    this->_ser(root);
    char *result = new char[ser_data.size() + 1];
    for (int i = 0; i < ser_data.size(); i++) {
      result[i] = ser_data[i];
    }
    result[ser_data.size()] = '\0';
    return result;
  }
  TreeNode *Deserialize(char *str) {
    this->des_str = str;
    return _des();
  }
};

int main() {
  Solution s;
  auto root = s.Deserialize("1,2,$,$,301,$,$");
  print_tree(root);
  return 0;
}
