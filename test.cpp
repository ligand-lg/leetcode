#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> test() {
  vector<vector<int>> r;
  r.push_back(vector<int>{1, 2, 3});
  r.push_back(vector<int>{1, 2, 3, 4, 5});
  return r;
}

int main() {
  auto result = test();
  sort(result.begin(), result.end(),
       [](const vector<int>& a, const vector<int>& b) {
         return a.size() > b.size();
       });

  for (auto r : result) {
    for (auto a : r) {
      cout << a;
    }
    cout << endl;
  }
  return 0;
}