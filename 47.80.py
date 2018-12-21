class Solution:
    def permuteUnique(self, nums, sorted=False):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not sorted:
            nums.sort()
        if len(nums) == 0:
            return [[]]
        len_n = len(nums)
        ans = []
        for i in range(len_n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            n = nums.pop(i)
            sub_ans = self.permuteUnique(nums, sorted=True)
            for a in sub_ans:
                a.insert(0, n)
                ans.append(a)
            nums.insert(i, n)
        return ans

t = Solution()
print(t.permuteUnique([1,1,2]))