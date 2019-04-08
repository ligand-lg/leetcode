// 无限背包问题（每种物品有无限个） -- dp解法
#include <vector>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

// 物品容量数组、物品价值数组、背包总容量
int dp_package(const vector<int>& ws, const vector<int>& vs, int pw) {
  // 下标表示容量，值表示当前容量能装下的最大价值
  int* dp = new int[pw + 1];
  int item_count = ws.size();
  int w = 0;
  dp[w++] = 0;
  for (; w <= pw; w++) {
    for (int i = 0; i < item_count; i++) {
      int w_max_value = 0;
      if (w >= ws[i]) {
        w_max_value = max(w_max_value, vs[i] + dp[w - ws[i]]);
      }
      w_max_value = max(w_max_value, dp[w - 1]);
    }
  }
  return dp[pw];
}

int main() { return 0; }
