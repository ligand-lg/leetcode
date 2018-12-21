# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        def bsearch(l, r):
            if l >= r:
                if intervals[l].start < newInterval.start:
                    return l + 1
                else: 
                    return l
            mid = (l + r) // 2
            if intervals[mid].start == newInterval.start:
                return mid
            elif intervals[mid].start > newInterval.start:
                return bsearch(l, mid-1)
            return bsearch(mid+1, r)
        ans = []
        if len(intervals) == 0:
            return [newInterval]
        the_index = bsearch(0, len(intervals)-1)
        intervals.insert(the_index, newInterval)
        i = 0
        for i in range(the_index):
            ans.append(intervals[i])
       
        while i < len(intervals):
            if not ans or ans[-1].end < intervals[i].start:
                ans.append(intervals[i])
            else:
                ans[-1].end = max(ans[-1].end, intervals[i].end)
            i += 1
        return ans

t = Solution()
for e in (t.insert([Interval(1,2), Interval(3,5),Interval(6,7),Interval(8,10),Interval(12,16)], Interval(4,8))):
    print(e.start, e.end)
print('-------')
for e in (t.insert([], Interval(4,8))):
    print(e.start, e.end)
print('---------')
for e in (t.insert([Interval(1,7)], Interval(4,8))):
    print(e.start, e.end)
print('---------')
for e in (t.insert([Interval(1,7)], Interval(1,8))):
    print(e.start, e.end)
print('---------')
for e in (t.insert([Interval(1,5), Interval(6, 8)], Interval(9,10))):
    print(e.start, e.end)
print('---------')