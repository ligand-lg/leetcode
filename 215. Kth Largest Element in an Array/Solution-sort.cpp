//
// Created by ligand on 2019-05-14.
//
/**
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  int partition(vector<int> &nums, int begin, int end) {
    if (begin > end)
      return -1;
    if (begin == end)
      return begin;

    int mid_num = nums[begin];
    int left = begin + 1, right = end;

    while (left < right) {
      while (nums[left] <= mid_num && left < right)
        left++;
      while (nums[right] > mid_num && left < right)
        right--;
      swap(nums[left], nums[right]);
    }

    if (nums[left] > mid_num)
      left--;
    swap(nums[begin], nums[left]);
    return left;
  }

 public:
  int findKthLargest(vector<int> &nums, int k) {
    int size = nums.size();
    int k_index = size - k;
    int res, begin = 0, end = size - 1;
    do {
      res = partition(nums, begin, end);
      if (res > k_index)
        end = res - 1;
      else
        begin = res + 1;
    } while (res != k_index);
    return nums[k_index];
  }
};

int main() {
  Solution s;
  vector<int> test_case = {9, 2, 3, 4};
  cout << s.findKthLargest(test_case, 4);
}
