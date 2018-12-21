class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        last = None
        for n in nums:
            if n != last:
                nums[i] = n
                last = n
                i += 1
        return i

t = Solution()
nums = [1,1,2,3,3,5,8]
print(t.removeDuplicates(nums), nums)

            
            

