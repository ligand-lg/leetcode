# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        header = ListNode(None)
        header.next = head
        l = header
        r = header
        while n > 0:
            r = r.next
            n -= 1
        while r.next:
            r = r.next
            l = l.next
        l.next = l.next.next
        return header.next


t = Solution()
l = t.removeNthFromEnd(ListNode(1), 1)
while l:
    print(l.val)
    l = l.next
