#include "../leetcode.h"

typedef int64_t myint;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    bool positive = (numerator >= 0 && denominator >= 0) ||
                    (numerator <= 0 && denominator <= 0);

    myint num = abs(myint(numerator));
    myint denom = abs(myint(denominator));
    myint remainder;

    myint intPart = 0;
    vector<char> facPart;
    map<myint, myint> remainders;

    intPart = num / denom;
    remainder = num - intPart * denom;

    const size_t MAXTIME = 10000;
    for (size_t i = 0; i < MAXTIME && remainder != 0; i++) {
      // find reapting
      map<myint, myint>::iterator it = remainders.find(remainder);
      if (it != remainders.end()) {
        facPart.insert(facPart.begin() + (*it).second, '(');
        facPart.push_back(')');
        break;
      }

      // eval next
      remainders.insert(pair<myint, myint>(remainder, i));
      remainder = remainder * 10;
      char tmp = '0' + remainder / denom;
      facPart.push_back(tmp);
      remainder = remainder - ((remainder / denom) * denom);
    }

    stringstream ss;
    if (!positive) {
      ss << "-";
    }
    ss << intPart;
    if (facPart.size() > 0) {
      ss << ".";
    }
    for (int i = 0; i < facPart.size(); i++) {
      ss << facPart[i];
    }

    return ss.str();
  }
};

int main() {
  Solution s;
  //  string res = s.fractionToDecimal(-50, 8);
  // res = s.fractionToDecimal(50, -8);
  string res = s.fractionToDecimal(-1, -2147483648);

  cout << res;
}