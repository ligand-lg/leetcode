#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    // [] --> []
    vector<vector<int>> result;
    if (nums.size() == 0) {
      vector<int> empty;
      result.push_back(empty);
    } else {
      // [a,[b]] -> f(b) + a*f(b)
      int a = nums[0];
      vector<int> subvector(nums.begin() + 1, nums.end());
      vector<vector<int>> sub_subsets = subsets(subvector);
      int sub_size = sub_subsets.size();
      for (int i = 0; i < sub_size; i++) {
        vector<int> copy(sub_subsets[i]);
        copy.push_back(a);
        sub_subsets.push_back(copy);
      }
      result = sub_subsets;
    }
    return result;
  }
};

int main() {
  Solution t;
  vector<int> test_data = {1, 2, 3};
  vector<vector<int>> result = t.subsets(test_data);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}