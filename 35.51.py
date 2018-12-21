class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def bsearch(start, end):
            mid = int((start+end)/2)
            if nums[mid] == target:
                return mid
            if start == end:
                if nums[start] < target:
                    return start + 1
                else:
                    return start
            # start > end:
            if nums[mid] > target:
                if start == mid:
                    if nums[start] < target:
                        return start + 1
                    else:
                        return start
                return bsearch(start, mid-1)
            else:
                return bsearch(mid+1, end)
        return bsearch(0, len(nums)-1)

t = Solution()
print(t.searchInsert([1,3], 0))
