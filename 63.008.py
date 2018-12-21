class Solution:
    def __init__(self):
        self.__c_tmp = {}

    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        整个坐标系以0开始
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        end_x = len(obstacleGrid[0]) - 1
        end_y = len(obstacleGrid) - 1
        # 存放障碍节点信息，（x，y，从原点到该点的路径数，路径中没有其他的障碍点
        tmp = []
        # 经过障碍点的路径数
        obstacle_path = 0
        for i, row in enumerate(obstacleGrid):
            for j, mark in enumerate(row):
                if mark is 1:
                    num = self.path_count(0, 0, j, i)
                    for x1, y1, n in tmp:
                        num -= n * self.path_count(x1, y1, j, i)
                    tmp.append((j, i, num))
                    obstacle_path += num * self.path_count(j, i, end_x, end_y)
        return self.path_count(0, 0, end_x, end_y) - obstacle_path

    def path_count(self, x1, y1, x2, y2):
        """
        点（x1，y1）到点（x2， y2）的路径数
        :rtype: int
        """
        x_d = x2 - x1
        y_d = y2 - y1
        ans = 0
        if x_d >= 0 and y_d >= 0:
            ans = self.c(x_d+y_d, x_d)
        return ans

    def c(self, p, k):
        """
        求解组合数, 使用缓存
        :type p: int, 总数
        :type k: int, 目标数
        :rtype: int
        """
        if k > p/2:
            k = p - k
        if (p, k) in self.__c_tmp.keys():
            return self.__c_tmp[(p,k)]
        elif k == 0:
            return 1
        else:
            ans = self.c(p-1, k) + self.c(p-1, k-1)
            self.__c_tmp[(p,k)] = ans
            return ans


d = [
    [0, 1, 0],
    [1, 0, 0],
    [0, 0, 0]
]
s = Solution()
print(s.uniquePathsWithObstacles(d))
