#include "../leetcode.h"

class Solution {
  vector<int> arr;
  int helper(int start, int end) {
    if ((end - start) == 1) return min(arr[start], arr[end]);
    if (start > end) return 0;
    int mid = (start + end) / 2;
    if (arr[start] > arr[mid])
      return helper(start, mid);
    else if (arr[mid] > arr[end])
      return helper(mid, end);
    return min(helper(start, mid), helper(mid + 1, end));
  }

 public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    int size = rotateArray.size();
    if (size <= 0) return 0;
    this->arr = rotateArray;

    // 正常顺序
    if (arr[0] < arr[size - 1]) return arr[0];
    return helper(0, size - 1);
  }
};

int main() {
  Solution s;
  vector<int> test_case{3, 4, 5, 6, 0, 2};
  cout << s.minNumberInRotateArray(test_case);
}