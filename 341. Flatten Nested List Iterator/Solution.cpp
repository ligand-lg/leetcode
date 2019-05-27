//
// Created by fry on 2019-05-27
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class NestedInteger {
 public:
  bool isInteger() const;
  int getInteger() const;
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  stack<vector<NestedInteger>::iterator> begins, ends;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    begins.push(nestedList.begin());
    ends.push(nestedList.end());
  }

  int next() {
    hasNext();
    return (begins.top()++)->getInteger();
  }

  bool hasNext() {
    while (!begins.empty()) {
      if (begins.top() == ends.top()) {
        begins.pop();
        ends.pop();
      } else {
        auto ele = begins.top();
        if (ele->isInteger())
          return true;
        begins.top()++;
        auto &subList = ele->getList();
        begins.push(subList.begin());
        ends.push(subList.end());
      }
    }
    return false;
  }
};
