//
// Created by ligand on 2019-05-13.
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
  void rotate(vector<vector<int>> &matrix) {
    const int size = matrix.size();


    // (i,j) <--> (j,i)
    int tmp;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j <= i; j++) {
        tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }

    // (i,j) <--> (i, size - j)
    for (int i = 0; i < size; i++) {
      for (int j = 0, k = size - 1; j < k; j++, k--) {
        tmp = matrix[i][j];
        matrix[i][j] = matrix[i][k];
        matrix[i][k] = tmp;
      }
    }

  }
};
