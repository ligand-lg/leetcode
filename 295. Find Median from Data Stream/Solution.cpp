//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(logn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class MedianFinder {
  priority_queue<int> mins; // 左半部分，最大堆记录
  priority_queue<int, vector<int>, greater<int>> maxs; // 右半部分，最小堆记录
  // 合法情况，(0, 0) (0, 1), (1, 0)
  int left_more;
  int right_more;

 public:
  MedianFinder() : mins(), maxs(), left_more(0), right_more(0) {}

  void addNum(int num) {
    if (mins.empty() || mins.top() >= num) {
      mins.push(num);
      left_more++;
    } else {
      maxs.push(num);
      right_more++;
    }
    // (1, 1) -> (0, 0)
    if (left_more == 1 && right_more == 1)
      left_more = right_more = 0;
    else if (left_more == 2) {
      // (2, 0) -> (0,0)
      maxs.push(mins.top());
      mins.pop();
      left_more = 0;
    } else if (right_more == 2) {
      // (0, 2) -> (0, 0)
      mins.push(maxs.top());
      maxs.pop();
      right_more = 0;
    }
  }

  double findMedian() {
    if (left_more == 0 && right_more == 0)
      return ((double) mins.top() + (double) maxs.top()) / 2.0;
    else if (left_more == 1)
      return (double) mins.top();
    else
      return (double) maxs.top();
  }
};
