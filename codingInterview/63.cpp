//
// Created by ligand on 2019-04-25.
//

#include "../leetcode.h"

class MinHeap {
  priority_queue<int> maxheap;
 public:
  int top() {
    return -1 * maxheap.top();
  }
  void pop() {
    maxheap.pop();
  }
  void push(int n) {
    maxheap.push(-1 * n);
  }
  size_t size() {
    return maxheap.size();
  }
  bool empty() {
    return maxheap.empty();
  }
};

class Solution {
  // 左边最大堆
  priority_queue<int> left_heap;
  // 右边最小堆
  MinHeap right_heap;

 public:
  void Insert(int num) {
    if (left_heap.empty()) {
      left_heap.push(num);
      return;
    }
    if (right_heap.empty()) {
      if (num < left_heap.top()){
        left_heap.push(num);
        right_heap.push(left_heap.top());
        left_heap.pop();
      }else {
        right_heap.push(num);
      }
      return;
    }
    // 偶数
    if (left_heap.size() == right_heap.size()) {
      if (num > right_heap.top()) {
        right_heap.push(num);
        left_heap.push(right_heap.top());
        right_heap.pop();
      } else {
        left_heap.push(num);
      }
    } else {
      // 奇数
      if (num < left_heap.top()) {
        left_heap.push(num);
        right_heap.push(left_heap.top());
        left_heap.pop();
      } else {
        right_heap.push(num);
      }
    }
  }

  double GetMedian() {
    if (left_heap.size() == right_heap.size())
      return (double) (left_heap.top() + right_heap.top()) / 2.0;
    return (double) left_heap.top();
  }

};

int main() {
  Solution s;
  s.Insert(5);
  s.Insert(2);
  s.Insert(3);
  cout << s.GetMedian();
  return 0;
}
