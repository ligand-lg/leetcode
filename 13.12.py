class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        unit = {'I': 1,'V': 5,'X': 10,'L': 50,'C': 100,'D': 500,'M': 1000}
        l = list(map(lambda c: unit[c], s))
        result = 0
        for i in range(len(l) - 1):
            if l[i] >= l[i+1]:
                result += l[i]
            else:
                result -= l[i]
        return result + l[-1]
t = Solution()
print(t.romanToInt('IV'))