//
// Created by fry on 2019-05-19
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> tmp(nums1.begin(), nums1.begin() + m);
    int i, j, k;
    i = j = k = 0;
    int end = m + n;
    while (k < end) {
      while ((i < m && j >= n) || (i < m && tmp[i] <= nums2[j]))
        nums1[k++] = tmp[i++];
      while ((j < n && i >= m) || (j < n && nums2[j] < tmp[i]))
        nums1[k++] = nums2[j++];
    }
  }
};
