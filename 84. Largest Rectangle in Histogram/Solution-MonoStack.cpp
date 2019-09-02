/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */
#include "../leetcode.h"

// 单调栈版本, 单调递增栈
class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
      stack<int> sk;
      int size = heights.size();
      vector<pair<int,int>> border(size);
      for (int i = 0; i < size; ++i) {
        border[i] = make_pair(i, i);
      }
      for (int i = 0; i < size; ++i) {
        while(!sk.empty() && heights[sk.top()] > heights[i]) {
          border[sk.top()].second = i - 1;
          border[i].first = border[sk.top()].first;
          sk.pop();
        }
        sk.push(i);
      }
      int remider;
      if (!sk.empty())
        remider = sk.top();
      while(!sk.empty()) {
        border[sk.top()].second = remider;
        sk.pop();
      }

      int ans = 0;
      for (int i = 0; i < size; ++i) {
        ans = max(ans, heights[i] * (border[i].second - border[i].first + 1));
      }
      return ans;
    }
};

int main() {

  return 0;
}
