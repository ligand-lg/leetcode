class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        len_s = len(s)
        if len_s == 0:
            return 0
        i = 0
        d = {}
        result = 1
        for j in range(len_s):
            c = s[j]
            if c not in d.keys() or d[c] < i:
                d[c] = j
            else:
                if j - i > result:
                    result = j - i
                    if result == 4:
                        print(i,j)
                i = d[c] + 1
                d[c] = j
        if len_s - i > result:
            return len_s - i
        return result

t = Solution()
print(t.lengthOfLongestSubstring("abcabcbb"))