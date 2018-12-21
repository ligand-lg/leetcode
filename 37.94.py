class Solution:
    def solveSudoku(self, board, ans):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def setValue(index, value):
            i, j, k = index
            board[i][j] = str(value)
            xs[i].discard(value)
            ys[j].discard(value)
            zs[k].discard(value)
            empty_index.remove((i, j, k))
            print('set {} to {} is {}'.format(index, value, ans[i][j]==str(value)))
            update_cell_may()

        def unSet(index):
            i, j, k = index
            ele = int(board[i][j])
            xs[i].add(ele)
            ys[j].add(ele)
            zs[k].add(ele)
            empty_index.append(index)
            print('unset {}'.format(index))

        def update_cell_may():
            for i,j,k in empty_index:
                cell_may[(i,j,k)] = xs[i].intersection(ys[j]).intersection(zs[k])

        def uniqu(index):
            xs = cell_may[index]
            ys = cell_may[index]
            zs = cell_may[index]
            for k in cell_may.keys():
                if k == index:
                    continue
                if k[0] == index[0]:
                    xs = xs.difference(cell_may[k])
                if k[1] == index[1]:
                    ys = ys.difference(cell_may[k])
                if k[2] == index[2]:
                    zs = zs.difference(cell_may[k])
            if len(xs) == 1:
                return xs.pop()
            if len(ys) == 1:
                return ys.pop()
            if len(zs) == 1:
                return zs.pop()
            return False

        def get_guess_index():
            guess_index = empty_index[0]
            min_num = len(cell_may[guess_index])
            for __i in empty_index:
                if min_num > len(cell_may[__i]):
                    min_num = len(cell_may[__i])
                    guess_index = __i
            return guess_index

        def backtracking(action):
            print('-------------wrong---------------')
            # 还原数据
            for index in action:
                unSet(index)

        # 三个维度上，可能的值
        xs = [set([1, 2, 3, 4, 5, 6, 7, 8, 9]) for i in range(9)]
        ys = [set([1, 2, 3, 4, 5, 6, 7, 8, 9]) for i in range(9)]
        zs = [set([1, 2, 3, 4, 5, 6, 7, 8, 9]) for i in range(9)]
        # 某个空缺位置的可能值
        cell_may = {}
        # 所有的空缺位置
        empty_index = []

        # 初始化 xs、ys、zs、empty_index
        for i in range(9):
            for j in range(9):
                ele = board[i][j]
                if ele == '.':
                    empty_index.append((i, j, i//3+(j//3)*3))
                else:
                    ele = int(ele)
                    xs[i].discard(ele)
                    ys[j].discard(ele)
                    zs[i//3+(j//3)*3].discard(ele)
        # 从 xs、ys、zs、empty_index 中更新 cell_may
        update_cell_may()

        def helper():
            action = []
            ''' stage 1 化简'''
            print('stag1----')
            stage1_find = True
            while stage1_find:
                stage1_find = False
                ii = len(empty_index) - 1
                while ii >= 0:
                    i,j,k = empty_index[ii]
                    possible = cell_may[(i,j,k)]
                    if len(possible) == 0:
                        backtracking(action)
                        return False
                    if len(possible) == 1:
                        stage1_find = True
                        action.append((i,j,k))
                        setValue((i, j, k), possible.pop())
                    else:
                        uniqu_result = uniqu((i,j,k))
                        if uniqu_result:
                            stage1_find = True
                            action.append((i,j,k))
                            setValue((i,j,k), uniqu_result)
                    ii -= 1
            ''' stage 1之后没有完成则开始猜，注意：猜错之后得通过 action 来还原数据 '''
            if len(empty_index) == 0:
                return True
            print('stag2----')
            guess_index = get_guess_index()
            for guess_value in cell_may[guess_index]:
                print('guess {} to {}'.format(guess_index, guess_value))
                setValue(guess_index, guess_value)
                if helper():
                    print('guess right: {} to {}'.format(guess_index, guess_value))
                    return True
                print('guess wrong: {} to {}'.format(guess_index, guess_value))
                unSet(guess_index)
                update_cell_may()
            backtracking(action)
            return False
        helper()
                
        


martix = [
    [".",".",".",".",".","7",".",".","9"],
    [".","4",".",".","8","1","2",".","."],
    [".",".",".","9",".",".",".","1","."],
    [".",".","5","3",".",".",".","7","2"],
    ["2","9","3",".",".",".",".","5","."],
    [".",".",".",".",".","5","3",".","."],
    ["8",".",".",".","2","3",".",".","."],
    ["7",".",".",".","5",".",".","4","."],
    ["5","3","1",".","7",".",".",".","."]
]
ans = [
    ["3","1","2","5","4","7","8","6","9"],
    ["9","4","7","6","8","1","2","3","5"],
    ["6","5","8","9","3","2","7","1","4"],
    ["1","8","5","3","6","4","9","7","2"],
    ["2","9","3","7","1","8","4","5","6"],
    ["4","7","6","2","9","5","3","8","1"],
    ["8","6","4","1","2","3","5","9","7"],
    ["7","2","9","8","5","6","1","4","3"],
    ["5","3","1","4","7","9","6","2","8"]
]
t = Solution()
t.solveSudoku(martix, ans)
for line in martix:
    print(line)
check = True
for i in range(9):
    for j in range(9):
        if martix[i][j] != '.' and martix[i][j] != ans[i][j]:
            check = False
print(check)
