class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ans = nums[0] + nums[1] + nums[2]
        len_num = len(nums)
        diff = abs(ans - target)
        for i, a_i in enumerate(nums[:-2]):
            if i > 0 and a_i == nums[i-1]:
                continue
            j = i + 1
            k = len_num - 1
            while j < k:
                _sum = nums[i] + nums[j] + nums[k]
                if abs(_sum - target) < diff:
                    ans = _sum
                    diff = abs(ans - target)
                if _sum == target:
                    return target
                elif _sum < target:
                    j += 1
                else:
                    k -= 1
        return ans

t = Solution()
print(t.threeSumClosest([0, 0, 0, 10], -10))
