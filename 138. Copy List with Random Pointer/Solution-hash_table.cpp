//
// Created by fry on 2019-05-24
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;

    map<Node *, Node *> hash_table;
    hash_table[nullptr] = nullptr;
    Node *q = nullptr;

    // 创建节点
    for (Node *p = head; p != nullptr; p = p->next) {
      q = new Node(p->val, nullptr, nullptr);
      hash_table[p] = q;
    }

    // 链接 next 和 random
    for (Node *p = head; p != nullptr; p = p->next) {
      q = hash_table[p];
      // for next
      q->next = hash_table[p->next];
      // for random
      q->random = hash_table[p->random];
    }

    return hash_table[head];
  }
};
