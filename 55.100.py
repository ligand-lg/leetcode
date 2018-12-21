class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_p = 0
        end = 0
        for i in range(len(nums)):
            if i + nums[i] > max_p:
                max_p = i + nums[i]
            if i == end:
                if end == max_p and i != len(nums) - 1:
                    return False
                end = max_p
        return True

t = Solution()
print(t.canJump([2,3,1,1,4]))
print(t.canJump([3,2,1,0,4]))
print(t.canJump([0,1]))

