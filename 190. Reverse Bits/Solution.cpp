#include "../leetcode.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;        
        for (int i = 0; i < 32; i++) {
            r = (r << 1) | (n & 1u);
            n = n >> 1;
        }
        return r;
    }
};

int main2() {
  Solution s;
  uint32_t r = s.reverseBits(43261596); // 964176192
  r = s.reverseBits(4294967293); // 3221225471
  r = s.reverseBits(4294967293);
}