#include "../leetcode.h"

class Solution {
public:
	void replaceSpace(char *str,int len) {
      if (str == NULL) return;
      int cnt = 0;
      for (int i = 0; i < len; ++i) {
        cnt += str[i] == ' ' ? 3:1;
      }
      for (int i = len - 1, j = cnt- 1; i >= 0; --i) {
        if (str[i] == ' ') {
          str[j--] = '0';
          str[j--] = '2';
          str[j--] = '%';
        }else {
          str[j--] = str[i];
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