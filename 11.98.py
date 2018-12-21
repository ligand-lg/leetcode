class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        reuslt = 0
        while i < j:
            area = min(height[i], height[j]) * (j - i)
            if area > reuslt:
                reuslt = area
            if height[i] < height[j]:
                # i go to right
                k = i + 1
                while k < j and height[k] <= height[i]:
                    k += 1
                i = k
            else:
                k = j - 1
                while k > i and height[k] <= height[j]:
                    k -= 1
                j = k
        return reuslt

t = Solution()
print(t.maxArea([2,8]))
