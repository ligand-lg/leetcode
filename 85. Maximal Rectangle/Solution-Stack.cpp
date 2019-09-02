/**
 *
 * T(n) = O(n^3)
 * S(n) = O(n)
 */
#include "../leetcode.h"

class Solution {
  int max_area(const vector<int> &h) {
    vector<pair<int, int>> border(h.size());
    for (int i = 0; i < h.size(); ++i) {
      border[i] = make_pair(i, i);
    }
    stack<int> sk;
    for (int i = 0; i < h.size(); ++i) {
      while(!sk.empty() && h[sk.top()] > h[i]) {
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
    for (int i = 0; i < h.size(); ++i) {
      ans = max(ans, h[i] * (border[i].second - border[i].first + 1));
    }
    return ans;
  }
 public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    vector<int> h(matrix[0].size(), 0);
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < h.size(); ++j) {
        if (matrix[i][j] == '0')
          h[j] = 0;
        else
          ++ h[j];
      }
      ans = max(ans, max_area(h));
    }
    return ans;
  }
};
