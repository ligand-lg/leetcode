#include "../leetcode.h"

class Solution {
 public:
  bool Find(int target, vector<vector<int>> array) {
    bool find = false;
    if (array.size() > 0) {
      int row = array.size();
      int col = array[0].size();
      int now_row = 0;
      int now_col = col - 1;
      while (now_row < row && now_col >= 0) {
        int cur_val = array[now_row][now_col];
        if (cur_val == target) {
          find = true;
          break;
        } else if (cur_val < target) {
          now_row++;
        } else {
          now_col--;
        }
      }
      cout << "now_row:" << now_row << "\tnow_col:" << now_col <<endl;
    }
    return find;
  }
};

int main() {
  Solution s;
  vector<vector<int>> test_case;
  test_case.push_back(vector<int>{1, 2, 8, 9});
  test_case.push_back(vector<int>{2, 4, 9, 12});
  test_case.push_back(vector<int>{4, 7, 10, 13});
  test_case.push_back(vector<int>{6, 8, 11, 15});
  cout << s.Find(7, test_case);
}