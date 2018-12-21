class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        ans = [[-1 for i in range(n)] for i in range(n)]
        def getNextIndex(x, y, the_length):
            if x == 1 and y != the_length:
                return (1, y+1)
            elif y == the_length and x != the_length:
                return (x+1, the_length)
            elif x == the_length and y != 1:
                return (the_length, y-1)
            return (x-1, 1)
        value = 0
        index_base = -1
        while n > 0:
            the_level_nums = (4*n - 4) or 1
            index_base += 1
            index_x = 1
            index_y = 1
            for i in range(the_level_nums):
                value += 1
                ans[index_x-1+index_base][index_y-1+index_base] = value
                index_x, index_y = getNextIndex(index_x, index_y, n)
            n -= 2
        return ans

t = Solution()
for line in t.generateMatrix(4):
    print(line)




