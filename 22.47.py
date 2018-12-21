
class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        def help(a, b, exit_str):
            """
            :type a: int, left left parenthes
            :type b: int, need to close left parenthes
            :exit List[str], exit str
            """
            if a == 0:
                if b == 0:
                    return [''.join(exit_str)]
                else:
                    exit_str.append(')')
                    ans =  help(a, b-1, exit_str)
                    exit_str.pop()
                    return ans
            elif b == 0:
                exit_str.append('(')
                ans =  help(a-1, b+1, exit_str)
                exit_str.pop()
                return ans
            else:
                ans = []
                exit_str.append('(')
                ans.extend(help(a-1, b+1, exit_str))
                exit_str.pop()
                exit_str.append(')')
                ans.extend(help(a, b-1, exit_str))
                exit_str.pop()
                return ans
        return help(n, 0, [])

t = Solution()
print(t.generateParenthesis(4))