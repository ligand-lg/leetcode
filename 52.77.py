class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        marks = [[0 for i in range(n)] for i in range(n)]
        def setValue(i, j):
            left_j = j - 1
            right_j = j + 1
            for _i in range(i+1, n):
                 # 垂直方向
                marks[_i][j] += 1
                # 斜率为1
                if left_j >= 0:
                    marks[_i][left_j] += 1
                 # 斜率为-1
                if right_j < n:
                    marks[_i][right_j] += 1
                left_j -= 1
                right_j += 1

        def unSetValue(i, j):
            left_j = j - 1
            right_j = j + 1
            for _i in range(i+1, n):
                 # 垂直方向
                marks[_i][j] -= 1
                # 斜率为1
                if left_j >= 0:
                    marks[_i][left_j] -= 1
                 # 斜率为-1
                if right_j < n:
                    marks[_i][right_j] -= 1
                left_j -= 1
                right_j += 1

        def helper(level):
            if level == n:
                return 1
            ans = 0 
            for i in range(n):
                if marks[level][i] == 0:
                    setValue(level, i)
                    ans += helper(level+1)
                    unSetValue(level, i)
            return ans
        return helper(0)


t = Solution()
print(t.totalNQueens(11))
