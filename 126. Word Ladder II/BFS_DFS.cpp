/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

// 双向遍历 + BFS + DFS
class Solution {
 private:
  void getPaths(const string &beginWord, const string &endWord,
                const unordered_map<string, vector<string>> &children,
                vector<string> &path, vector<vector<string>> &res) {
    if (beginWord == endWord) {
      res.push_back(path);
      res.back().push_back(endWord);
      return;
    }
    const auto &nexts = children.find(beginWord);
    if (nexts != children.end()) {
      for (const auto &next : nexts->second) {
        path.push_back(beginWord);
        getPaths(next, endWord, children, path, res);
        path.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    vector<vector<string>> res;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return res;

    int n = beginWord.size();
    // 双向遍历的当前节点
    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};
    // 是否找到答案 - 两个集合中有公共节点
    bool found_res = false;
    // q1 集合不是左节点。用于确定当前节点和下一个节点的父子关系。
    bool backward = false;
    // 邻接表
    unordered_map<string, vector<string>> children;

    // BFS
    while (!q1.empty() && !q2.empty() && !found_res) {
      if (q1.size() > q2.size()) {
        std::swap(q1, q2);
        backward = !backward;
      }
      // one level
      for (const auto &word : q1) dict.erase(word);
      for (const auto &word : q2) dict.erase(word);
      unordered_set<string> q;

      for (const auto &word : q1) {
        string curr(word);
        for (int i = 0; i < n; ++i) {
          char old_c = curr[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            curr[i] = c;
            const string *parent = backward ? &curr : &word;
            const string *child = backward ? &word : &curr;
            if (q2.count(curr)) {
              found_res = true;
              children[*parent].push_back(*child);
            } else if (dict.count(curr) && !found_res) {
              q.insert(curr);
              children[*parent].push_back(*child);
            }
          }
          curr[i] = old_c;
        }
      }
      std::swap(q1, q);
    }

    // DFS
    vector<string> path;
    getPaths(beginWord, endWord, children, path, res);
    return res;
  }
};
int main() {
  vector<string> test_case = {"hot", "dot", "dog", "lot", "log", "cog"};
  vector<string> test_case2 = {"hot", "dog"};
  vector<string> test_case3 = {
      "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay",
      "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal",
      "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit",
      "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row",
      "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has",
      "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu",
      "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy",
      "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply",
      "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan",
      "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye",
      "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot",
      "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib",
      "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm",
      "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk",
      "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag",
      "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic",
      "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his",
      "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod",
      "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib",
      "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr",
      "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap",
      "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx",
      "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set",
      "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao",
      "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap",
      "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky",
      "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo",
      "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva",
      "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep",
      "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed",
      "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum",
      "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem",
      "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen",
      "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit",
      "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken",
      "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin",
      "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui",
      "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo",
      "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas",
      "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio",
      "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit",
      "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix",
      "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid",
      "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil",
      "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig",
      "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty",
      "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug",
      "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot",
      "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism",
      "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego",
      "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big",
      "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot",
      "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo",
      "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid",
      "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref",
      "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned",
      "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid",
      "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax",
      "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe",
      "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob"};

  string begin = "hit";
  string begin2 = "hot";
  string begin3 = "cet";

  string end = "cog";
  string end2 = "dog";
  string end3 = "ism";

  Solution s;
  auto res = s.findLadders(begin3, end3, test_case3);
  for (const auto &line : res) {
    for (const auto &s : line) {
      cout << s << "  ";
    }
    cout << endl;
  }
}
