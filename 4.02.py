class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def bsearch(start_a, end_a):
            i = (start_a + end_a)//2
            j = half_len + 2 - i # i 增加了1，j 增加了1
            if a[i-1] <= b[j] and b[j-1] <= a[i]:
                return i, j
            elif a[i-1] > b[j]:
                return bsearch(start_a, i-1)
            else:
                return bsearch(i+1, end_a)

        n = len(nums1)
        m = len(nums2)
        a, b = nums1, nums2
        if n > m:
            n, m, a, b = m, n, b, a
        a.insert(0, float('-inf'))
        a.append(float('inf'))
        b.insert(0, float('-inf'))
        b.append(float('inf'))
        half_len = (m+n+1)//2
        # 本来是0 到 n, 数组首位添加了-inf，变为 1 -> n+1
        i, j = bsearch(1, n+1)
        if (m+n) % 2:
            return max(a[i-1], b[j-1])
        else:
            return (max(a[i-1], b[j-1]) + min(a[i], b[j])) / 2

t = Solution()
print(t.findMedianSortedArrays([4,5,6], [1,2,3]))