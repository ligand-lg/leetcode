// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    size_t start = 1, end = n;
    size_t mid;
    while (start != end) {
      mid = (start + end) / 2;
      if (isBadVersion(mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
/*
非常直接的查找题目。使用二分查找
递归式子：如果 mid is true，找[start, mid], 否则找[mid+1, end]
递归出口：start == end

*/