class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        import math
        n = len(matrix)
        end_i = math.floor(n/2)
        end_j = math.ceil(n/2)
        n -= 1
        for i in range(end_i):
            for j in range(end_j):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[n-j][i]
                matrix[n-j][i] = matrix[n-i][n-j]
                matrix[n-i][n-j] = matrix[j][n-i]
                matrix[j][n-i] = tmp
t = Solution()
m = [
  [ 5, 1, 9,11,1],
  [ 2, 4, 8,10,1],
  [13, 3, 6, 7,1],
  [15,14,12,16,1],
  [10,10,10,10,10]
]
t.rotate(m)
print(m)
