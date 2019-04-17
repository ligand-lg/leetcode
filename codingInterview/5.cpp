#include "../leetcode.h"

class Solution {
 public:
  void push(int node) { stack1.push(node); }

  int pop() {
    if (stack2.size() == 0) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    if (stack2.size() == 0) {
      throw "can not pop a empty queue!";
    }
    int result = stack2.top();
    stack2.pop();
    return result;
  }

 private:
  stack<int> stack1;
  stack<int> stack2;
};