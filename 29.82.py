class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        def help(divd, divs):
            if divd < divs:
                return 0
            ans = 1
            new_divs = divs
            while divd >= new_divs:
                new_divs <<=  1
                ans <<= 1
            ans >>= 1
            new_divs >>= 1
            return ans + help(divd - new_divs, divs)
        isNegetive = (dividend > 0 and divisor < 0) or (dividend <0 and divisor >0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        ans = help(dividend, divisor)
        ans = ans * (-1 if isNegetive else 1)
        if ans < -2147483648 or ans > 2147483647:
            ans = 2147483647
        return ans

t = Solution()
print(t.divide(2147483648,1))