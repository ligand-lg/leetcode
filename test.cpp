#include "leetcode.h"


int main(int, char **) {
  vector<int> v = {1,2,3,4,5};
  reverse(v.begin()+1, v.begin()+4);
  for (int i = 0; i < v.size(); i++){
    cout << v[i] << "";
  }

  return 0;
}
