#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int test[10];
  memset(test, 1, sizeof(int) * 10);
  for (int i = 0; i < 10; i++) {
    cout << i << ": " << test[i] << endl;
  }
}
