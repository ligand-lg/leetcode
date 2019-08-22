#include "../leetcode.h"

class Solution {
  bool help(const vector<int> &seq, int begin, int end) {
    if (begin >= end) return true;
    int root_val = seq[end-1];
    int new_end = end - 1;
    int left_end = begin;
    while(left_end < new_end && seq[left_end] <= root_val) {
      ++left_end;
    }
    for (int i = left_end; i < new_end; ++i) {
      if (seq[i] < root_val) 
        return false;
    }
    return help(seq, begin, left_end) && help(seq, left_end, new_end);
  }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
      if (sequence.empty()) return false;
      return help(sequence, 0, sequence.size());
    }
};

int main() {
  Solution s;
  cout << s.VerifySquenceOfBST(vector<int>());
}