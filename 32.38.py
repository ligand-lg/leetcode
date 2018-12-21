class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        tmp = [None] * len(s)
        my_stack = []
        for i, c in enumerate(s):
            if c == '(':
                my_stack.append(i)
            elif len(my_stack) > 0:
                tmp[my_stack.pop(-1)] = 1
                tmp[i] = 1
        max_sub_valid = 0
        valid = 0
        for mark in tmp:
            if mark:
                valid += 1
            else:
                max_sub_valid = max(max_sub_valid, valid)
                valid = 0
        return max(max_sub_valid, valid)

t = Solution()
print(t.longestValidParentheses('()(()'))


                


