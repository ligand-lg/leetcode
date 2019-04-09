#include "../leetcode.h"

/*
 * 转移方程: f(n) = [...f(n - len(w[i])), a[n]]，其中 i = [...wordDict];
 * 初始值:   f(0) = [[]];
 * 零值:    f(n) = [] (n < 0);
 *
 * T(n) = O(n*m)，其中 n 为目标字符串长度，m 为字典元素个数;
 * S(n) = O(n);
 */

class Solution {
  vector<bool> dp_mark;
  vector<vector<vector<string>>> dp;
  string str;
  vector<string> wd;
  vector<vector<string>> it(int i) {
    // 已经有缓存，直接使用
    if (dp_mark[i]) return dp[i];

    // 没有缓存，计算
    vector<vector<string>> result;
    for (auto s : wd) {
      int start_index = i - s.length();
      // 当前串比word长
      if (start_index >= 0) {
        // 比较两个字符串完全相等
        bool is_same = true;
        for (auto c : s) {
          if (c != str[start_index++]) {
            is_same = false;
            break;
          }
        }
        if (is_same) {
          for (auto pre_result : it(i - s.length())) {
            pre_result.push_back(s);
            result.push_back(pre_result);
          }
        }
      }
    }
    dp[i] = result;
    dp_mark[i] = true;
    return result;
  }

 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int count = s.length();
    this->str = s;
    this->wd = wordDict;
    // dp三维字符串数组，值为[]表示不可达（零值）
    this->dp = vector<vector<vector<string>>>(count + 1);
    //  表示第 i 个dp是否初始化过
    this->dp_mark = vector<bool>(count + 1, false);
    // init
    // dp[0] = [[]]
    this->dp[0] = vector<vector<string>>(1);
    this->dp_mark[0] = true;
    vector<string> result;
    for (auto line : it(count)) {
      // change formart
      string str_line;
      if (line.size() > 0) {
        str_line = line[0];
        for (int i = 1; i < line.size(); i++)
          str_line = str_line + " " + line[i];
      }
      if (str_line.length() > 0) result.push_back(str_line);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<string> data{"apple", "pen", "applepen", "pine", "pineapple"};
  auto r = s.wordBreak("catsandog", data);
  cout << "result: " << endl;
  for (auto line : r) {
    cout << line << endl;
  }
  return 0;
}