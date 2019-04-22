#include "../leetcode.h"

class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> times;
    for (int num : numbers) {
      auto find = times.find(num);
      if (find == times.end()) {
        times[num] = 0;
      }
      times[num] += 1;
    }
    int result = 0;
    int hanf = numbers.size() / 2;
    for (auto r : times) {
      if (r.second > hanf) {
        result = r.first;
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.MoreThanHalfNum_Solution(vector<int>{1, 2, 3, 4, 8, 8, 8, 8, 8});
}
