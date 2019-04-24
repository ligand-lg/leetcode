//
// Created by ligand on 2019-04-23.
// 此题为复制的答案

#include "../leetcode.h"

class Solution {
 public:
  bool isNumeric(char *string) {
    int i = 0;
    if (string[i] == '+' || string[i] == '-' || IsNum(string[i])) {
      while (string[++i] != '\0' && IsNum(string[i]));
      if (string[i] == '.') {
        if (IsNum(string[++i])) {
          while (string[++i] != '\0' && IsNum(string[i]));
          if (string[i] == 'e' || string[i] == 'E') {
            i++;
            if (string[i] == '+' || string[i] == '-' || IsNum(string[i])) {
              while (string[++i] != '\0' && IsNum(string[i]));
              if (string[i] == '\0') return true;
              else return false;
            } else return false;
          } else if (string[i] == '\0') return true;
          else return false;
        } else if (string[++i] == '\0') return true;
        else return false;
      } else if (string[i] == 'e' || string[i] == 'E') {
        i++;
        if (string[i] == '+' || string[i] == '-' || IsNum(string[i])) {
          while (string[++i] != '\0' && IsNum(string[i]));
          if (string[i] == '\0') return true;
          else return false;
        } else return false;
      } else if (string[i] == '\0') return true;
      else return false;
    } else return false;
  }

  bool IsNum(char ch) {
    if (ch < '0' || ch > '9') return false;
    else return true;
  }
};
