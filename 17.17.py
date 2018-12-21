class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        import math
        d_2_c = {
            '2': ['a','b','c'],
            '3': ['d','e','f'],
            '4': ['g','h','i'],
            '5': ['j','k','l'],
            '6': ['m','n','o'],
            '7': ['p','q','r','s'],
            '8': ['t','u','v'],
            '9': ['w','x','y','z']
        }
        len_d = len(digits)
        if len_d == 0:
            return []
        div = 1
        divs = []
        i = len_d - 1
        ans = []
        while i >= 0:
            divs.insert(0, div)
            div *= len(d_2_c[digits[i]])
            i -= 1
        for m in range(1, div+1):
            tmp = []
            for i, d in enumerate(divs):
                index = math.ceil(m/d) - 1
                tmp.append(d_2_c[digits[i]][index])
                m %= d
            ans.append(''.join(tmp))
        return ans

t = Solution()
print(t.letterCombinations('299999'))