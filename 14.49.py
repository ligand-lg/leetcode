class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        end = len(strs[0])
        for s in strs:
            if end > len(s):
                end = len(s)
        i = 0
        while i < end:
            c = strs[0][i]
            all_same = True
            for s in strs:
                if s[i] != c:
                    all_same = False
                    break
            if not all_same:
                break
            i += 1
        return strs[0][:i]

t = Solution()
print(t.longestCommonPrefix(["flower","flow","flight"]))