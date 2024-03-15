#include "../leetcode.h"

class Solution {
public:
  int compareVersion(string version1, string version2) {
    const int V1BIG = 1;
    const int V2BIG = -1;
    const int EQUAL = 0;

    int preDot1 = -1, preDot2 = -1;
    while ((preDot1 < int(version1.length())) &&
           (preDot2 < int(version2.length()))) {
      int dot1 = version1.find('.', preDot1 + 1);
      int dot2 = version2.find('.', preDot2 + 1);

      if (dot1 == -1) {
        dot1 = version1.length();
      }
      if (dot2 == -1) {
        dot2 = version2.length();
      }

      int revision1 = stoi(version1.substr(preDot1 + 1, dot1 - preDot1 - 1));
      int revision2 = stoi(version2.substr(preDot2 + 1, dot2 - preDot2 - 1));

      if (revision1 > revision2) {
        return V1BIG;
      } else if (revision2 > revision1) {
        return V2BIG;
      }

      preDot1 = dot1;
      preDot2 = dot2;
    }

    for (int i1 = preDot1 + 1; i1 < version1.length(); i1++) {
      if (version1[i1] != '0' && version1[i1] != '.') {
        return V1BIG;
      }
    }
    for (int i2 = preDot2 + 1; i2 < version2.length(); i2++) {
      if ((version2[i2]) != '0' && version2[i2] != '.') {
        return V2BIG;
      }
    }

    return EQUAL;
  }
};

int main() {
  Solution s;
  int res = s.compareVersion("0.0.1", "0.001");
  cout << res;
}