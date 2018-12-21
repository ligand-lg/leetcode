# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        ans = []
        for interval in intervals:
            i = len(ans) - 1
            while i >= 0:
                a = ans[i]
                if not (interval.start > a.end or interval.end < a.start):
                    interval.start = min (interval.start, a.start)
                    interval.end = max(interval.end, a.end)
                    ans.pop(i)
                i -= 1
            ans.append(interval)
        return ans

t = Solution()
for e in (t.merge([Interval(2,3),Interval(4,5),Interval(6,7),Interval(8,9),Interval(1,10)])):
    print(e.start, e.end)



        