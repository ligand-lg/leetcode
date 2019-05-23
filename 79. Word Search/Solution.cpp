//
// Created by fry on 2019-05-22
//

/**
 *
 * T(n) = O(?)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
  int rows, cols;
  bool dfs(vector<vector<char>> &used, const string &word, int last_index, int row, int col) {
    if (last_index == word.size())
      return true;

    if (row < 0 || row >= rows || col < 0 || col >= cols)
      return false;

    if (used[row][col] != word[last_index])
      return false;

    used[row][col] = 0;
    bool res = dfs(used, word, last_index +1, row + 1, col)
        || dfs(used, word, last_index + 1, row - 1, col)
        || dfs(used, word, last_index + 1, row, col - 1)
        || dfs(used, word, last_index + 1, row, col + 1);

    used[row][col] = word[last_index];
    return res;
  }

 public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.empty())
      return true;

    if (board.empty() || board[0].empty())
      return false;

    this->rows = board.size(), this->cols = board[0].size();
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col)
        if (dfs(board, word, 0, row, col))
          return true;
    }

    return false;
  }
};

int main() {
  vector<vector<char>> test_case;
  test_case.push_back(vector<char>{'a', 'b', 'c', 'e'});
  test_case.push_back(vector<char>{'s', 'f', 'c', 's'});
  test_case.push_back(vector<char>{'a', 'd', 'e', 'e'});

  Solution s;
  cout << s.exist(test_case, "abcced");

}
