#include "../leetcode.h"

class WordDictionary {

  WordDictionary *child[26];
  bool isEnd;

public:
  WordDictionary() {
    for (int i = 0; i < 26; ++i) {
      this->child[i] = nullptr;
    }
    isEnd = false;
  }

  void addWord(string word) {
    WordDictionary *node = this;
    for (char c : word) {
      size_t idx = c - 'a';
      if (node->child[idx] == nullptr) {
        node->child[idx] = new WordDictionary();
      }
      node = node->child[idx];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    WordDictionary *node = this;
    size_t wLen = word.length();
    for (size_t i = 0; i < wLen; ++i) {
      if (word[i] == '.') {
        for (size_t j = 0; j < 26; ++j) {
          if (node->child[j] != nullptr &&
              node->child[j]->search(word.substr(i + 1, wLen - (i + 1)))) {
            return true;
          }
        }
        return false;
      } else {
        size_t idx = (word[i] - 'a');
        if (node->child[idx] == nullptr) {
          return false;
        }
        node = node->child[idx];
      }
    }
    return node != nullptr && node->isEnd;
  }
};
int main() {
  WordDictionary w;
  w.addWord("abc");
  cout << w.search("abc");
  cout << w.search("a..");
  cout << w.search("abd");
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */