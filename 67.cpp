#include "leetcode.h"

class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int carry = 0;
    int len_a = a.length();
    int len_b = b.length();
    int max_len = max(len_a, len_b);
    int bit_a, bit_b, s;
    // 倒数第i个
    for (int i = 0; i < max_len; i++) {
      bit_a = 0;
      bit_b = 0;
      if (i < len_a) bit_a = a[len_a - i - 1] - '0';
      if (i < len_b) bit_b = b[len_b - i - 1] - '0';

      s = bit_a ^ bit_b ^ carry;
      s += '0';
      result.insert(0, 1, char(s));
      carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry);
    }
    if (carry > 0) result.insert(0, 1, char(carry + '0'));
    return result;
  }
};

int main() {
  Solution s;
  cout << s.addBinary("11", "10");
  return 0;
}