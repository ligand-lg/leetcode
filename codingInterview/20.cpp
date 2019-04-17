#include "../leetcode.h"


class Solution {
  stack<int> data;
  stack<int> mins;
public:
    void push(int value) {
      data.push(value);        
      if (mins.empty() || value <= mins.top()) {
        mins.push(value);
      }
    }
    void pop() {
       if (data.top() == mins.top()) {
         mins.pop();
       }
       data.pop();
    }
    int top() {
      return data.top();
    }
    int min() {
        return mins.top();
    }
};