#include "../leetcode.h"

class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int i = 0;
    int size = citations.size();
    while (i < size && citations[i] < size - i) {
      ++i;
    }
    return size - i;
  }
};