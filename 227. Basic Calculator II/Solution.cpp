#include "../leetcode.h"

class Solution {
public:
  bool isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
  int calculate(string s) {
    vector<int> nums;
    vector<char> ops;

    size_t i = 0;
    while (i < s.length()) {
      if (isOp(s[i])) {
        ops.push_back(s[i]);
        ++i;
      } else {
        int j = i;
        while (j < s.length() && (!isOp(s[j]))) {
          ++j;
        }
        nums.push_back(stoi(s.substr(i, j - i)));
        i = j;
      }
    }

    char lastOp = '+';
    for (i = 0; i < ops.size(); ++i) {
      char op = ops[i];
      if (op == '*') {
        int res = nums[i] * nums[i + 1];
        nums[i] = 0;
        nums[i + 1] = res;
        ops[i] = lastOp;
      } else if (op == '/') {
        int res = nums[i] / nums[i + 1];
        nums[i] = 0;
        nums[i + 1] = res;
        ops[i] = lastOp;
      } else {
        lastOp = op;
      }
    }
    int res = nums[0];
    for (i = 0; i < ops.size(); ++i) {
      if (ops[i] == '+') {
        res += nums[i + 1];
      } else {
        res -= nums[i + 1];
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  int res = s.calculate("12-3*4/2");
  cout << res;
}