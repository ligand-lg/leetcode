#include "../leetcode.h"

class Solution {
public:
  int execOp(int a, int b, char op) {
    if (op == '+') {
      return a + b;
    }
    if (op == '-') {
      return a - b;
    }
    if (op == '*') {
      return a * b;
    }
    return 0;
  }

  vector<int> diffWaysToCompute(string expression) {
    bool isPureNumber = true;
    vector<int> res;

    for (size_t i = 0; i < expression.length(); ++i) {
      if (!isdigit(expression[i])) {
        isPureNumber = false;
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right = diffWaysToCompute(expression.substr(i + 1));
        for (auto n : left) {
          for (auto m : right) {
            res.push_back(execOp(n, m, expression[i]));
          }
        }
      }
    }

    if (isPureNumber) {
      res.push_back(stoi(expression));
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> res = s.diffWaysToCompute("1+1+1");
  cout << res[0];
}