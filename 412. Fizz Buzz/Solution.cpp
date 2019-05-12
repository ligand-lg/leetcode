//
// Created by ligand on 2019-05-11.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    if (n <= 0)
      return vector<string>();

    vector<string> res(n);
    bool mul_three, mul_five;
    for (int i = 0; i < n; i++) {
      mul_three = (i + 1) % 3 == 0;
      mul_five = (i + 1) % 5 == 0;
      if (mul_three && mul_five) {
        res[i] = "FizzBuzz";
      } else if (mul_three) {
        res[i] = "Fizz";
      } else if (mul_five) {
        res[i] = "Buzz";
      } else {
        res[i] = to_string(i + 1);
      }
    }
    return res;
  }
};
