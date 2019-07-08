/**
 *
 * T(n) = O(m * n)
 * S(n) = O(m * n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int ladderLength(string beginWord, const string &endWord, vector<string> &wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return 0;

    int n = beginWord.size();
    int size = wordList.size();

    unordered_map<string, vector<int>> adjs;

    for (int i = 0; i < size; ++i) {
      auto &s = wordList[i];
      for (int j = 0; j < n; ++j) {
        auto key(s);
        key[j] = '*';
        adjs[key].push_back(i);
      }
    }

    vector<bool> visited(size, false);

    queue<string *> nodes;
    nodes.push(&beginWord);
    // end mark
    nodes.push(nullptr);
    int res = 1;

    while (!nodes.empty()) {
      string *node = nodes.front();
      nodes.pop();
      if (node == nullptr) {
        if (!nodes.empty()) {
          nodes.push(nullptr);
          ++res;
        }
      } else {
        if (*node == endWord) {
          return res;
        }
        for (int i = 0; i < n; ++i) {
          char c = (*node)[i];
          (*node)[i] = '*';
          for (auto index : adjs[*node]) {
            if (!visited[index]) {
              nodes.push(&wordList[index]);
              visited[index] = true;
            }
          }
          (*node)[i] = c;
        }
      }
    }
    return 0;
  }
};
