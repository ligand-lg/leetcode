#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int> > t;
  cout << t.size() << "*" << t.at(0).size();
  vector<int> a;
  t.push_back(a);
  cout << t.size() << "*" << t[0].size();
  return 0;
}