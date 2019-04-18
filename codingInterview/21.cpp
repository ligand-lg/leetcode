#include "../leetcode.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
      int size = pushV.size();
      if (size == 0) return true;
      stack<int> helper;
      int push_index = 0;
      for (int i = 0; i < size; i++) {
        // 辅助栈栈顶不是目标，入栈。
        while (helper.empty() || helper.top() != popV[i]){
          helper.push(pushV[push_index++]);
          if (push_index >= size) break;
        }
        if (helper.top() == popV[i]) 
          helper.pop();
        else 
          return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  cout << s.IsPopOrder(vector<int>{}, vector<int>{});
}