#include "../leetcode.h"

class Trie {

  Trie *child[26];
  bool isEnd;

public:
  Trie() {
    for (int i = 0; i < 26; ++i) {
      this->child[i] = nullptr;
    }
    isEnd = false;
  }

  void insert(string word) {
    Trie *node = this;
    for (char c : word) {
      size_t idx = c - 'a';
      if (node->child[idx] == nullptr) {
        node->child[idx] = new Trie();
      }
      node = node->child[idx];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie *node = this->getStartWith(word);
    return node != nullptr && node->isEnd;
  }

  bool startsWith(string prefix) {
    return this->getStartWith(prefix) != nullptr;
  }

  Trie *getStartWith(string prefix) {
    if (prefix.length() == 0) {
      return nullptr;
    }
    Trie *node = this;
    for (char c : prefix) {
      size_t idx = c - 'a';
      if (node->child[idx] == nullptr) {
        return nullptr;
      }
      node = node->child[idx];
    }

    return node;
  }
};
int main() {
  Trie t;
  cout << t.search("apple");
  t.insert("apple");
  cout << t.search("apple");
  cout << t.startsWith("app");
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */