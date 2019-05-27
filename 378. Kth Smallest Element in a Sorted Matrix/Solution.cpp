//
// Created by fry on 2019-05-27
//

/**
 *
 * T(n) = O(klogk)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  struct triple {
    int row;
    int col;
    int val;
    triple(int _row, int _col, int _val) : row(_row), col(_col), val(_val) {}
  };
  struct cmp {
    bool operator()(const triple &a, const triple &b) { return a.val > b.val; }
  };
 public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<triple, vector<triple>, cmp> min_heap;

    for (int col = 0; col < matrix[0].size(); ++col) {
      min_heap.push(triple(0, col, matrix[0][col]));
    }
    int rows = matrix.size();

    while (k > 1) {
      auto t = min_heap.top();
      min_heap.pop();
      --k;
      if (t.row + 1 < rows)
        min_heap.push(triple(t.row + 1, t.col, matrix[t.row + 1][t.col]));
    }
    return min_heap.top().val;
  }
};
