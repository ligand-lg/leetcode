class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        end = len(nums)
        while i < end:
            if nums[i] == val:
                nums.pop(i)
                end -= 1
            else:
                i += 1
        return i

t = Solution()
nums = [1]
print(t.removeElement(nums, 2), nums)