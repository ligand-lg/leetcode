# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ans = ListNode(None)
        a_p = ans
        p = l1
        q = l2
        while p and q:
            if p.val < q.val:
                a_p.next = p
                while p and p.val < q.val:
                    p = p.next
                    a_p = a_p.next
            else:
                a_p.next = q
                while q and q.val <= p.val:
                    q = q.next
                    a_p = a_p.next
        a_p.next = p or q
        return ans.next


t = Solution()
l1 = ListNode(1)
l1.next = ListNode(2)
l1.next.next = ListNode(4)
l2 = ListNode(1)
l2.next = ListNode(3)
p = t.mergeTwoLists(l1, l2)
while p:
    print(p.val)
    p = p.next
