# py 中 int 就是下取整
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        def reverse(x):
            result = 0
            div = int(x/10)
            mod = x % 10
            while div != 0:
                result = result * 10 + mod
                x = div
                div = int(x/10)
                mod = x % 10
            return result*10 + mod
        result = False
        if (x >=0 and reverse(x) == x):
            result = True
        return result
