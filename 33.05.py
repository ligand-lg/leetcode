class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def help(left, right):
            if left > right:
                return -1
            mid = int((left + right)/2)
            if target == nums[mid]:
                return mid
            # normal 
            if nums[left] < nums[right]:
                if target > nums[mid]:
                    return help(mid+1, right)
                else:
                    return help(left, mid-1)
            else:
                if nums[left] <= nums[mid]:
                    if nums[left] <= target < nums[mid]:
                        return help(left, mid-1)
                    else:
                        return help(mid+1, right)
                else:
                    if nums[mid] < target <= nums[right]:
                        return help(mid+1, right)
                    else:
                        return help(left, mid-1)
        return help(0, len(nums)- 1)

t = Solution()
print(t.search([4,5,6,7,0,1,2], 2))
