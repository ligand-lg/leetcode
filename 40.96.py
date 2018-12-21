class Solution:
    def combinationSum2(self, candidates, target):
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
                if i > start and candidates[i] == candidates[i-1]:
                    i += 1
                    continue
                sub_ans = help(i+1, t-candidates[i])
                for a in sub_ans:
                    a.insert(0, candidates[i])
                ans.extend(sub_ans)
                i += 1
            return ans

        candidates.sort()
        return help(0, target)

t = Solution()
print(t.combinationSum2([2,5,2,1,2], 6))