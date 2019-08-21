#include "../leetcode.h"

class Solution {
  int help(const vector<int> &v, int b, int e) {
    int m = (b + e) / 2;
    if (v[b] < v[e]) return v[b];
    if (v[m] > v[b]) return help(v, m + 1, e);
    if (v[m] < v[e]) return help(v, b + 1, m);
    return min(v[m], v[e]);
  }

 public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;
    return help(rotateArray, 0, rotateArray.size() - 1);
  }
};

int main() {
  Solution s;
  vector<int> test_case{
      6501, 6828, 6963, 7036, 7422, 7674, 8146, 8468, 8704, 8717, 9170, 9359,
      9719, 9895, 9896, 9913, 9962, 154,  293,  334,  492,  1323, 1479, 1539,
      1727, 1870, 1943, 2383, 2392, 2996, 3282, 3812, 3903, 4465, 4605, 4665,
      4772, 4828, 5142, 5437, 5448, 5668, 5706, 5725, 6300, 6335};
  cout << s.minNumberInRotateArray(test_case);
}