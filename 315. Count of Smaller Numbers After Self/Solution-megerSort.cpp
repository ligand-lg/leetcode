//
// Created by fry on 2019-05-17
//

/**
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  // 结果
  vector<int> res;
  //数据
  vector<int> nums;
  // 排序的过程中下标会变，需要下标映射：index[new_index] --> old_index
  vector<int> index_map;

  void merge(int begin, int end, int begin2, int end2) {
    if (begin >= end || begin2 >= end2)
      return;

    int left_i = begin, right_i = begin2, i = 0;
    vector<int> tmp(end - begin + end2 - begin2);
    vector<int> new_index(end - begin + end2 - begin2);

    while (left_i < end || right_i < end2) {
      // 右边用完 或者 左边小，使用左边
      if (right_i >= end2 || (left_i < end && nums[left_i] <= nums[right_i])) {
        tmp[i] = nums[left_i];
        // 更新结果
        res[index_map[left_i]] += i - (left_i - begin);
        // 记录新的映射
        new_index[i] = index_map[left_i];
        left_i++;
      } else {
        // 使用右边
        tmp[i] = nums[right_i];
        new_index[i] = index_map[right_i];
        right_i++;
      }
      i++;
    }

    // 复制结果
    for (i = begin; i < end2; i++) {
      index_map[i] = new_index[i - begin];
      nums[i] = tmp[i - begin];
    }
  }

  // 前闭后开
  void mergeSort(int begin, int end) {
    if (begin + 1 >= end)
      return;
    int mid = (begin + end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, mid, mid, end);
  }

 public:
  vector<int> countSmaller(vector<int> &_nums) {
    nums = _nums;
    res = vector<int>(nums.size(), 0);
    index_map = vector<int>(nums.size());
    for (int i = 0; i < nums.size(); i++)
      index_map[i] = i;
    mergeSort(0, nums.size());
    return res;
  }
};

int main() {
  Solution s;
  vector<int> test_case = {51, 9, 21, 84, 66, 65, 36, 100, 41};
  for (auto n : s.countSmaller(test_case))
    cout << n << ",";
  cout << endl;
}
