# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """

        if head is None or head.next is None:
            return True

        # Step 1: Find middle using slow and fast
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse second half
        prev = None
        curr = slow
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # Step 3: Compare first and second half
        first, second = head, prev
        while second:  # only need to check second half
            if first.val != second.val:
                return False
            first = first.next
            second = second.next

        return True
