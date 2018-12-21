
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        header = ListNode(None)
        header.next = head
        p = header
        q = header.next.next
        while q:
            p.next.next = q.next
            q.next = p.next
            p.next = q
            p = q.next
            q = p.next.next if p.next else None
            # p, q = q + 2 , p + 2
        return header.next
l1 = ListNode(1)
# l1.next = ListNode(2)
# l1.next.next = ListNode(4)
# l1.next.next.next = ListNode(9)

t = Solution()
ans = t.swapPairs(l1)
while ans:
    print(ans.val)
    ans = ans.next
        


