//
// Created by fry on 2019-05-29
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Codec {
  TreeNode *strToNode(const string &str) {
    if (str == "null")
      return nullptr;
    int val = stoi(str);
    return new TreeNode(val);
  }

  string nodeTostr(TreeNode *node) {
    if (node == nullptr)
      return "null";
    return to_string(node->val);
  }

 public:
  string serialize(TreeNode *root) {
    if (root == nullptr)
      return "[]";

    queue<TreeNode *> tmp;
    vector<TreeNode *> res;

    res.push_back(root);
    tmp.push(root->left);
    tmp.push(root->right);

    // 序列化
    while (!tmp.empty()) {
      auto ele = tmp.front();
      tmp.pop();
      if (ele == nullptr) {
        res.push_back(nullptr);
        continue;
      }
      res.push_back(ele);
      tmp.push(ele->left);
      tmp.push(ele->right);
    }

    // 去除尾部多余的null
    while (res.size() > 2) {
      if (res[res.size() - 1] == res[res.size() - 2] && res[res.size() - 1] == nullptr) {
        res.pop_back();
        res.pop_back();
      } else {
        break;
      }
    }

    // 转成字符串数组
    string res_str = "[";
    int i = 0;
    res_str += nodeTostr(res[i++]);
    while (i < res.size()) {
      res_str += ',' + nodeTostr(res[i++]);
    }
    res_str += ']';
    return res_str;
  }

  TreeNode *deserialize(string data) {
    if (data == "[]")
      return nullptr;

    if (data[0] != '[' || data.back() != ']')
      return nullptr;
    // 去掉开头、结尾的[]
    data.erase(0, 1);
    data.erase(data.size() - 1, data.size());

    // 从 str 到 node，node 没有连接起来
    vector<TreeNode *> nodes;
    string delimiter = ",", token;
    size_t pos = 0;
    while ((pos = data.find(delimiter)) != string::npos) {
      token = data.substr(0, pos);
      nodes.push_back(strToNode(token));
      data.erase(0, pos + delimiter.length());
    }
    // 最后还有一个
    nodes.push_back(strToNode(data));

    // 连接各个 node
    int i = 0;
    queue<TreeNode *> tmp;
    tmp.push(nodes[i++]);
    while (i < nodes.size()) {
      auto ele = tmp.front();
      tmp.pop();
      if (ele != nullptr) {
        ele->left = nodes[i];
        tmp.push(nodes[i++]);
        ele->right = nodes[i];
        tmp.push(nodes[i++]);
      }
    }
    return nodes[0];
  }
};

int main() {
  Codec s;
  TreeNode test_case(1, new TreeNode(2), new TreeNode(3, new TreeNode(4, new TreeNode(4), nullptr), new TreeNode(5)));
  auto str = s.serialize(&test_case);
  auto r = s.deserialize(str);
  cout << str << endl;
  print_tree(r);
}
