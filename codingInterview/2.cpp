#include "../leetcode.h"

class Solution {
 public:
  void replaceSpace(char *str, int length) {
    if (str == nullptr || length == 0) return;
    int blank_nums = 0;
    int origin_len = 0;
    char *p = str;
    for (char *p = str; *p != '\0'; p++) {
      if (*p == ' ') blank_nums++;
      origin_len++;
    }

    int new_len = origin_len + 2 * blank_nums;
    if (new_len + 1 > length) return;
    str[new_len] = '\0';

    int end_index = origin_len - 1;
    int new_end_index = new_len - 1;
    while (blank_nums > 0) {
      if (str[end_index] == ' ') {
        str[new_end_index--] = '0';
        str[new_end_index--] = '2';
        str[new_end_index--] = '%';
        end_index--;
        blank_nums--;
      } else {
        str[new_end_index--] = str[end_index--];
      }
    }
  }
};

int main() {
  Solution s;
  char test_case[20] = " helloworld";
  s.replaceSpace(test_case, 20);
  cout << test_case<<"----";
  return 0;
}