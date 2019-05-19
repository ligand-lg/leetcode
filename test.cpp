#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 不使用 + 来实现加法
int getSum(int a, int b) {
  int c = 0;
  while (b != 0) {
    c = ((a & b) << 1);
    a ^= b;
    b = c;
  }
  return a;
}


int main() {
//  cout << getSum(-1, 1);
  string s1 = "hello";
  string s2 = "hellof";
  cout << (s1 == s2);

}
