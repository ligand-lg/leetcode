class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = [1]
        while n > 1:
            left = 0
            right = 0
            tmp = ans[0]
            new_ans = []
            while right < len(ans):
                if ans[right] != tmp:
                    new_ans.append(right-left)
                    new_ans.append(tmp)
                    tmp = ans[right]
                    left = right
                right += 1
            n -= 1
            new_ans.append(right-left)
            new_ans.append(tmp)
            ans = new_ans
        return ''.join([str(b) for b in ans])
    
t = Solution()
print(t.countAndSay(5))

                    



