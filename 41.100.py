class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = list(set(nums))
        nums.sort()
        i = 0
        len_num = len(nums)
        while i < len_num and nums[i] <= 0  :
            i += 1
        ans = 1
        while i < len_num:
            if ans != nums[i]:
                break
            ans += 1
            i += 1
        return ans

t = Solution()
print(t.firstMissingPositive([7,8,9,11,12]))