class Solution:
    def __init__(self):
        import math
        self.INT_MAX = math.pow(2, 31) - 1
        self.INT_MIN = math.pow(-2, 31)
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sigal = 1
        if (x < 0):
            sigal = -1
            x = -1 * x
        result = 0
        div = int(x/10)
        mod = x % 10
        while div != 0:
            result = result * 10 + mod
            x = div
            div = int(x/10)
            mod = x % 10
        result = result*10 + mod
        if result > self.INT_MAX or result < self.INT_MIN:
            result = 0
        return result * sigal

t = Solution()
print(t.reverse(1534236469))

