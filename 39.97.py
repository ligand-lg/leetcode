class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        len_c = len(candidates)
        def help(start, t):
            if t == 0:
                return [[]]
            i = start
            ans = []
            while i < len_c and candidates[i] <= t:
                sub_ans = help(i, t-candidates[i])
                for a in sub_ans:
                    a.insert(0, candidates[i])
                ans.extend(sub_ans)
                i += 1
            return ans

        candidates.sort()
        return help(0, target)

t = Solution()
print(t.combinationSum([2,3,6,7], 7))