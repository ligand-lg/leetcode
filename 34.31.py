class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        len_nums = len(nums)
        def help(start, end):
            if start > end:
                return len_nums, -1
            mid = int((start + end)/2)
            if nums[mid] == target:
                return min(help(start, mid-1)[0], mid), max(help(mid+1, end)[1], mid)
            elif nums[mid] > target:
                return help(start, mid-1)
            else:
                return help(mid+1, end)
        ans = list(help(0, len_nums-1))
        if ans[0] == len_nums:
            ans[0] = -1
        return ans

t = Solution()
print(t.searchRange([5,7,7,8,8,10], 80))