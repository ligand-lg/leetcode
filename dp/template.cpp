#include "../leetcode.h"

/*
 * 转移方程: f(n) = [...f(n - len(w[i])), a[n]]，其中 i = [...wordDict];
 * 初始值:   f(0) = [[]];
 * 零值:    f(n) = [] (n < 0);
 *
 * T(n) = O(n*m)，其中 n 为目标字符串长度，m 为字典元素个数;
 * S(n) = O(n);
 */