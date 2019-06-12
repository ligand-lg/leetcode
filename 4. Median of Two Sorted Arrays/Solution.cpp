/**
 *
 * T(n) = O(lg(min(m, n)))
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> &a = nums1;
    vector<int> &b = nums2;
    if (m > n) {
      swap(m, n);
      swap(a, b);
    }
    int begin = 0, end = m, half = (m + n + 1) / 2;
    int i, j;
    while (begin <= end) {
      i = (begin + end) / 2;
      j = half - i;
      if (i > 0 && j < n && a[i - 1] > b[j]) {
        end = i - 1;
        continue;
      }
      if (j > 0 && i < m && b[j - 1] > a[i]) {
        begin = i + 1;
        continue;
      }
      // i， j都已就绪
      int max_of_left, min_of_right;
      if (i == 0) {
        max_of_left = b[j - 1];
      } else if (j == 0) {
        max_of_left = a[i - 1];
      } else {
        max_of_left = max(a[i - 1], b[j - 1]);
      }
      if ((m + n) % 2 == 1) {
        return max_of_left;
      }
      if (i == m) {
        min_of_right = b[j];
      } else if (j == n) {
        min_of_right = a[i];
      } else {
        min_of_right = min(a[i], b[j]);
      }
      return (double) (min_of_right + max_of_left) / 2.0;
    }
    return -1;
  }
};
