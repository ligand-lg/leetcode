class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head
        len_list = 1
        p = head
        while p.next:
            len_list += 1
            p = p.next
        move_step = len_list - k%len_list
        if move_step == len_list:
            return head
        
        p.next = head
        for _ in range(len_list - k%len_list):
            head = head.next
            p = p.next
        p.next = None
        return head
        