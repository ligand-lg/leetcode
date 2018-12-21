class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.rstrip()
        return len(s) - s.rfind(' ') - 1
    
t = Solution()
print(t.lengthOfLastWord('Hello world'))
print(t.lengthOfLastWord('   '))
print(t.lengthOfLastWord(' hello  '))
print(t.lengthOfLastWord('  '))