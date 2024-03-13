#include "../leetcode.h"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;

    int i = 0;
    while (i < words.size()) {
      int lineLeftWidth = maxWidth;
      int end_idx = i;

      // words[i].length <= maxWidth. so at least one words
      lineLeftWidth = lineLeftWidth - words[end_idx].length();
      end_idx += 1;
      while (end_idx < words.size() &&
             lineLeftWidth > words[end_idx].length()) {
        lineLeftWidth = lineLeftWidth - (1 + words[end_idx].length());
        end_idx += 1;
      }

      // build the line
      stringstream ss;
      if (end_idx == words.size()) {
        // last line
        ss << words[i];

        for (int j = i + 1; j < end_idx; j++) {
          ss << " " << words[j];
        }
        for (int j = 0; j < lineLeftWidth; j++) {
          ss << " ";
        }
      } else {
        ss << words[i];

        int emptySlots = end_idx - i - 1;
        if (emptySlots == 0) {
          for (int j = 0; j < lineLeftWidth; j++) {
            ss << " ";
          }
        } else {
          int avgEmptyNum = lineLeftWidth / emptySlots;
          int leftEmptyNum = lineLeftWidth - (avgEmptyNum * emptySlots);
          for (int j = i + 1; j < end_idx; j++) {
            for (int k = 0; k < avgEmptyNum; k++) {
              ss << " ";
            }
            if ((j - i) <= leftEmptyNum) {
              ss << " ";
            }
            ss << " " << words[j];
          }
        }
      }

      res.push_back(ss.str());
      i = end_idx;
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<string> d{"This",          "is", "an", "example", "of", "text",
                   "justification."};
  int maxWitdh = 16;
  vector<string> res = s.fullJustify(d, maxWitdh);
  cout << res[0];
}