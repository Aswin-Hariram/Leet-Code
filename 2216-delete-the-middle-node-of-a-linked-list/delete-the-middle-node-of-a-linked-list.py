class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Case 1: Only one node → delete it
        if head is None or head.next is None:
            return None

        fast, slow = head, head
        prev = None

        # Step 1: Find middle with slow/fast pointers
        while fast and fast.next:
            fast = fast.next.next
            prev = slow
            slow = slow.next

        # Step 2: Delete middle node
        prev.next = slow.next

        return head
