//
// Created by ligand on 2019-04-22.
//
#include "../leetcode.h"

class Solution {
  vector<int> data;
  int k = 0;
  int firstK(int start, int end) {
    int result = -1;
    if (start <= end) {
      int mid = (start + end) / 2;
      if (data[mid] < k) {
        return firstK(mid + 1, end);
      } else if (data[mid] == k && ((mid == 0) || data[mid - 1] < k)) {
        return mid;
      } else {
        return firstK(start, mid - 1);
      }
    }
    return result;
  }
  int lastK(int start, int end) {
    int result = -1;
    if (start <= end) {
      int mid = (start + end) / 2;
      if (data[mid] > k) {
        return lastK(start, mid - 1);
      } else if (data[mid] == k
          && ((mid + 1) == this->data.size() || data[mid + 1] > k)) {
        return mid;
      } else {
        return lastK(mid + 1, end);
      }
    }
    return result;
  }
 public:
  int GetNumberOfK(vector<int> data, int k) {
    int result = 0;

    if (data.empty()) return result;

    this->data = data;
    this->k = k;
    int first = firstK(0, data.size() - 1);
    if (first >= 0) {
      int last = lastK(0, data.size() - 1);
      result = last - first + 1;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.GetNumberOfK(vector<int>{9}, 9);
  return 0;
}
