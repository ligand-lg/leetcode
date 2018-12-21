class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        factorials = [1,1,2,6,24,120,720,5040,40320]
        ans = []
        available = [True for i in range(10)]

        def ceil(x, y):
            return x//y + (1 if x % y else 0)
            
        def helper(_n, _k):
            if _k == 1 or _n == 1:
                i = 1
                while _n > 0:
                    if available[i]:
                        _n -= 1
                        ans.append(i)
                    i += 1
                return None
            find_index = ceil(_k, factorials[_n-1])
            have_cost = find_index
            i = 1
            while find_index > 1:
                while not available[i]:
                    i+= 1
                find_index -= 1
                i += 1
            while not available[i]:
                    i+= 1
            ans.append(i)
            available[i] = False
            helper(_n-1, _k - ((have_cost-1)*factorials[_n-1]))
        helper(n,k)
        return ''.join([str(i) for i in ans])

t = Solution()
print(t.getPermutation(9, 140321))


