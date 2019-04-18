#include "../leetcode.h"

class Solution {
  vector<int> seq;
  bool helper(int start, int end) {
    if (start >= end) return true;
    int right_start_index = start;
    int root_index = end;
    // left subtree
    while (right_start_index < end && seq[right_start_index] < seq[root_index])
      right_start_index++;
    // right subtree
    for (int i = right_start_index; i < end; i++) {
      if (seq[i] < seq[root_index]) return false;
    }
    return helper(start, right_start_index - 1) &&
           helper(right_start_index, end - 1);
  }

 public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() == 0) return false;
    this->seq = sequence;
    return helper(0, seq.size() - 1);
  }
};

int main() {
  Solution s;
  cout << s.VerifySquenceOfBST(vector<int>());
}