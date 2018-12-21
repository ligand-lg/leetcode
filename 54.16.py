class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        ans = []
        m = len(matrix) - 1
        if m < 0:
            return ans
        n = len(matrix[0]) - 1

        def helper(i, j, end_i, end_j):
            if i > end_i or j > end_j:
                return None
            for _j in range(j, end_j+1):
                if matrix[i][_j] != None:
                    ans.append(matrix[i][_j])
                    matrix[i][_j] = None
            for _i in range(i, end_i+1):
                if matrix[_i][end_j] != None:
                    ans.append(matrix[_i][end_j])
                    matrix[_i][end_j] = None
            for _j in reversed(range(j, end_j+1)):
                if matrix[end_i][_j] != None:
                    ans.append(matrix[end_i][_j])
                    matrix[end_i][_j] = None
            for _i in reversed(range(i, end_i+1)):
                if matrix[_i][j] != None:
                    ans.append(matrix[_i][j])
                    matrix[_i][j] = None
            helper(i+1, j+1, end_i-1, end_j-1)
        helper(0, 0, m, n)
        return ans
t = Solution()
print(t.spiralOrder([
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]))
print(t.spiralOrder([
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]))
print(t.spiralOrder([
    [1,2,3]
]))
print(t.spiralOrder([
    []
]))
print(t.spiralOrder([
    [1],[2],[3]
]))