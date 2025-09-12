# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: Optional[ListNode]
        :type left: int
        :type right: int
        :rtype: Optional[ListNode]
        """
        if not head or left == right:
            return head

        dummy = ListNode(0, head)
        prev = dummy

        # Step 1: Move prev to node before left
        for _ in range(left - 1):
            prev = prev.next

        # Step 2: Reverse sublist [left, right]
        curr = prev.next
        prev_sub = None
        for _ in range(right - left + 1):
            nxt = curr.next
            curr.next = prev_sub
            prev_sub = curr
            curr = nxt

        # Step 3: Reconnect
        prev.next.next = curr   # connect tail of reversed part
        prev.next = prev_sub    # connect prev to head of reversed part

        return dummy.next
