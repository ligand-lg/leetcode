//
// Created by ligand on 2019-04-23.
//

#include "../leetcode.h"

class Solution {
 public:
  // Parameters:
  //        numbers:     an array of integers
  //        length:      the length of array numbers
  //        duplication: (Output) the duplicated number in the array number
  // Return value:       true if the input is valid, and there are some duplications in the array number
  //                     otherwise false
  bool duplicate(int numbers[], int length, int *duplication) {
    vector<int> hash(length, 0);
    for (int i = 0; i < length; i++) {
      if (hash[numbers[i]] > 0) {
        *duplication = numbers[i];
        return true;
      }
      hash[numbers[i]] += 1;
    }
    return false;
  }
};

int main() {
  Solution s;
  int a[] = {};
  int result = -1;
  cout << s.duplicate(a, 0, &result);
  cout << "\t" << result;
  return 0;
}
