class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        left_parentheses = ['(', '[', '{']
        right_partheses = [')', ']', '}']
        for c in s:
            if c in left_parentheses:
                stack.append(c)
            elif c in right_partheses:
                if len(stack) == 0:
                    return False
                if right_partheses.index(c) != left_parentheses.index(stack.pop()):
                    return False
        if len(stack) != 0:
            return False
        return True

t = Solution()


