
/**
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */
#include "../leetcode.h"

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
      sort(numbers.begin(), numbers.end(), [](int a, int b)->int {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b < str_b + str_a;
      });
      string ans;
      for (auto item : numbers) {
        ans += to_string(item);
      }
      return ans;
    }
};