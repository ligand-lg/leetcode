class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return [[]]
        len_n = len(nums)
        ans = []
        for i in range(len_n):
            n = nums.pop(i)
            sub_ans = self.permute(nums)
            for a in sub_ans:
                a.insert(0, n)
                ans.append(a)
            nums.insert(i, n)
        return ans
            

t = Solution()
print(t.permute([1,2,3]))