#include "../leetcode.h"

class Solution {
public:
    void reOrderArray(vector<int> &v) {
      int end = v.size() - 1;
      bool swap_mark = true;
      while (swap_mark) {
        swap_mark = false;
        for (int i = 0; i < end; ++i) {
          if (v[i] % 2 == 0 && v[i+1]%2 != 0) {
            swap(v[i], v[i+1]);
            swap_mark = true;
          }
        }
      }
    }
};

int main() {
  Solution s;
  vector<int> test_case = {1,2,3,4,5,6, 7};
  s.reOrderArray(test_case);
  for (auto i : test_case) {
    cout << i << " ";
  }
}