#include "../leetcode.h"

class Solution {
 public:
  int InversePairs(vector<int> data) {
    if (data.size() < 2) return 0;
    vector<int> copy = vector<int>(data);
    return merge(data, copy, 0, data.size() - 1);
  }
  int merge(vector<int> &data, vector<int> &tmp, int start, int end) {
    if (start > end) return 0;

    if (start == end) {
      tmp[start] = data[start];
      return 0;
    }

    int half_len = (end - start + 1) / 2;
    int left_start = start;
    int left_end = start + half_len - 1;
    int right_start = start + half_len;
    int right_end = end;
    int left = merge(tmp, data, left_start, left_end);
    int right = merge(tmp, data, right_start, right_end);

    int i = left_end;
    int j = right_end;
    int tmp_index = right_end;
    int curr_count = 0;
    while (i >= left_start && j >= right_start) {
      if (data[i] > data[j]) {
        tmp[tmp_index--] = data[i--];
        curr_count += j - right_start + 1;
        curr_count %= 1000000007;
      } else {
        tmp[tmp_index--] = data[j--];
      }
    }
    while (i >= left_start) {
      tmp[tmp_index--] = data[i--];
    }
    while (j >= right_start) {
      tmp[tmp_index--] = data[j--];
    }
    return (left + right + curr_count) % 1000000007;
  }
};

int main() {
  Solution s;
  vector<int> test_case{3, 2, 1};
  auto r = s.InversePairs(test_case);
  cout << "r: " << r << endl;
  return 0;
}
