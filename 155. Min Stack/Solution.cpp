//
// Created by fry on 2019-05-17
//

/**
 *
 * T(n) = O(?)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class MinStack {
  stack<int> mins, elems;
 public:
  MinStack() : mins(), elems() {}
  void push(int x) {
    elems.push(x);
    if (mins.empty())
      mins.push(x);
    else
      mins.push(min(x, mins.top()));
  }
  void pop() {
    mins.pop();
    elems.pop();
  }
  int top() {
    return elems.top();
  }
  int getMin() {
    return mins.top();
  }
};
