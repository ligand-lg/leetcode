#include <vector>

class Solution
{
private:
  vector<int> cache = {0, 1, 2};

public:
  int climbStairs(int n)
  {
    for (int i = cache.size(); i <= n; i++)
    {
      cache.push_back(cache[i - 1] + cache[i - 2]);
    }
    return cache[n];
  }
};