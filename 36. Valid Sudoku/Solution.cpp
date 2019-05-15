//
// Created by ligand on 2019-05-15.
//

/**
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool rows[9][9];
    bool cols[9][9];
    bool subs[9][9];
    memset(rows, 0, 81);
    memset(cols, 0, 81);
    memset(subs, 0, 81);

    char c;
    int offset;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        c = board[i][j];
        if (c != '.') {
          offset = c - '1';

          if (rows[i][offset])
            return false;
          rows[i][offset] = true;

          if (cols[offset][j])
            return false;
          cols[offset][j] = true;

          if (subs[(i / 3) * 3 + j / 3][offset])
            return false;
          subs[(i / 3) * 3 + j / 3][offset] = true;
        }
      }
    }
    return true;
  }
};
