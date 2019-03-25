#include "leetcode.h"
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // sort
    vector<pair<int, int>> tmp;
    for (int i = 0; i < prices.size(); i++) {
      tmp.push_back(make_pair(prices[i], i));
    }
    sort(tmp.begin(), tmp.end());
    int left_index = 0;
    int right_index = tmp.size() - 1;
    while (left_index < right_index) {
      cout << "left: " << left_index <<"(" <<tmp[left_index].first <<"," <<tmp[left_index].second<<")"<<"\t";
      cout << "right: " << right_index <<"(" <<tmp[right_index].first <<"," <<tmp[right_index].second<<")"<<endl;
      if (tmp[left_index].second < tmp[right_index].second) {
        return tmp[right_index].first - tmp[left_index].first;
      }
      // move left_index or right_index base which was less
      int left_dis = tmp[left_index + 1].first - tmp[left_index].first;
      int right_dis = tmp[right_index].first - tmp[right_index - 1].first;
      if (left_dis < right_dis) {
        left_index++;
      } else {
        right_index--;
      }
    }
    return 0;
  }
};

int main() {
  Solution t;
  vector<int> test_data = {4, 1, 2};
  cout << t.maxProfit(test_data);
  return 0;
}