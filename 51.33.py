class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        marks = [[0 for i in range(n)] for i in range(n)]
        ans = []
        ans_index = []
        def new_ans():
            new_ans = [['.' for i in range(n)] for i in range(n)]
            for i in range(n):
                new_ans[i][ans_index[i]] = 'Q'
                new_ans[i] = ''.join(new_ans[i])
            ans.append(new_ans)

        def setValue(i, j):
            ans_index.append(j)
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
            ans_index.pop()
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
                new_ans()
                return True
            for i in range(n):
                if marks[level][i] == 0:
                    setValue(level, i)
                    helper(level+1)
                    unSetValue(level, i)
        helper(0)
        return ans

t = Solution()
for oneCase in t.solveNQueens(11):
    for line in oneCase:
        print(line)
    print('-------')