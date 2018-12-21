class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return int(self.c(m+n-2, m-1))

    def c(self, m, n):
        """
        求解组合数
        :type m: int, 底
        :type n: int, 顶
        :rtype: int
        """
        if n > m/2:
            n = m - n
        ans = 1
        for i in range(1, n+1):
            ans *= (m - i + 1)
        for i in range(1, n+1):
            ans /= i
        return ans


t = Solution()
print(t.uniquePaths(3, 3))
