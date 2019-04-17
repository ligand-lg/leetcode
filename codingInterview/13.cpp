#include "../leetcode.h"

class Solution {
 public:
  void reOrderArray(vector<int> &array) {
    // 使用交换排序
    int end = array.size() - 1;
    bool swap_mark = true;
    while (swap_mark) {
      swap_mark = false;
      for (int i = 0; i < end; i++) {
        // 当前为偶，下一个为奇数
        if ((array[i] % 2 == 0) && (array[i + 1] % 2 == 1)) {
          int tmp = array[i];
          array[i] = array[i+1];
          array[i+1] = tmp;
          swap_mark = true;
        }
      }
    }
  }
};
