class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # random quick sort, in-place
        def quick_sort(arr, start=0, end=-1):
            import random
            if end == -1:
                end = len(arr) - 1
            def quick_sort_recursive(start, end):
                if start < end:
                    pivot_index = random.randint(start, end)
                    arr[end], arr[pivot_index] = arr[pivot_index], arr[end]
                    left = start
                    right = end- 1
                    while left < right:
                        while left < right and arr[left] < arr[end]:
                            left += 1
                        while left < right and arr[right] >= arr[end]:
                            right -= 1
                        arr[left], arr[right] = arr[right], arr[left]
                    if arr[left] >= arr[end]:
                        arr[left], arr[end] = arr[end], arr[left]
                    else:
                        left += 1
                    quick_sort_recursive(start, left-1)
                    quick_sort_recursive(left+1, end)
            quick_sort_recursive(start, end)

        i = len(nums) - 1
        while i >= 0:
            j = len(nums) - 1
            while j > i:
                if nums[i] < nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
                    quick_sort(nums, start=i+1)
                    return None
                j -= 1
            i -= 1
        nums.sort()

t = Solution()
l = [1,2]
t.nextPermutation(l)
print(l)