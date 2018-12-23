class Solution:
    def __init__(self):
        self.tmp = {}
        self.grid = []
        self.max_x = -1
        self.max_y = -1

    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.grid = grid
        self.max_x = len(grid[0])
        self.max_y = len(grid)
        return self.helper(0, 0)

    def helper(self, x, y):
        if (x, y) in self.tmp.keys():
            return self.tmp[(x, y)]
        if x == self.max_x - 1 and y == self.max_y - 1:
            return self.grid[y][x]
        if x >= self.max_x or y >= self.max_y:
            return float('Inf')
        right = self.helper(x+1, y)
        down = self.helper(x, y+1)
        ans = right if right < down else down
        ans += self.grid[y][x]
        self.tmp[(x, y)] = ans
        return ans


t = Solution()
inp = [
    [1, 3, 1],
    [1, 5, 1],
    [4, 2, 1]
]
print(t.minPathSum(inp))
