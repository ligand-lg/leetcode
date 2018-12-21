class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = {}
        column = {}
        sub = {}
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c != '.' :
                    if i not in row:
                        row[i] = [c]
                    elif c in row[i]:
                        return False
                    else:
                        row[i].append(c)

                    if j not in column:
                        column[j] =[c]
                    elif c in column[j]:
                        return False
                    else:
                        column[j].append(c)

                    g = (i//3, j//3)
                    if g not in sub:
                        sub[g] = [c]
                    elif c in sub[g]:
                        return False
                    else:
                        sub[g].append(c)
        return True

t = Solution()
i = [
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
print(t.isValidSudoku(i))
