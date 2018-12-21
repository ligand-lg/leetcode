# Definition for singly-linked list.
class ListNode:
    def __init__(self, x, n=None):
        self.val = x
        self.next = n

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        header = ListNode(None)
        header.next = head
        h_p = e = header
        h = e_n = head
        for i in range(k):
            e = e_n
            e_n = e_n and e_n.next
        while e:
            # reverse [h, e]. h_p -> h ->...-> e -> e_n
            new_h = None
            e.next = None
            p = h
            q = h.next
            while q:
                p.next = new_h
                new_h = p
                p = q
                q = q.next
            p.next = new_h
            new_h = p
            e,h = h,e
            h_p.next = h
            e.next = e_n

            for i in range(k):
                h_p = h
                h = h.next
                e = e_n
                e_n = e_n and e_n.next
        return header.next



h = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
t = Solution()
h = t.reverseKGroup(ListNode(12), 3)
while h:
    print(h.val)
    h = h.next