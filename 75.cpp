#include <vector>
#include <iostream>
using namespace std;

// 问题抽象：只有0，1，2三种元素的数组排序。
// 要求：遍历一遍 + 常量空间复杂度
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // 下一个0元素位置
    int zero_index = 0;
    // 下一个2元素位置
    int two_index = nums.size() - 1;
    int i = 0;
    while (i <= two_index) {
      if (nums[i] == 0) {
        // 找到0，放在下一个0元素位置
        int tmp = nums[zero_index];
        nums[zero_index] = nums[i];
        nums[i] = tmp;
        zero_index++;
        i = i > zero_index ? i : zero_index;
      } else if (nums[i] == 2) {
        // 找到2， 放在下一个2元素位置
        int tmp = nums[two_index];
        nums[two_index] = nums[i];
        nums[i] = tmp;
        two_index--;
      } else {
        // 找到1，向后走
        i++;
      }
    }
  }
};
int main() {
  Solution t;
  vector<int> v;
  int a[] = {2,0,2,1,1,0};
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    v.push_back(a[i]);
  }
  t.sortColors(v);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout<<*it<<'\t';
  }
  return 0;
}