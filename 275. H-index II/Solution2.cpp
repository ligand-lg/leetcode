class Solution {
public:
  int hIndex(vector<int> &citations) {
    size_t n = citations.size();
    size_t start = 0;
    size_t end = n - 1;
    size_t mid;

    while (start != end) {
      mid = (start + end) / 2;
      if (citations[mid] >= n - mid) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    if (citations[start] >= n - start) {
      return n - start;
    } else {
      return 0;
    }
  }
};