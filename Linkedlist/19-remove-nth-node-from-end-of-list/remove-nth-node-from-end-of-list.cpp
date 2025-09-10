class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge cases like removing the head node
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next; 
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is just before the node to be deleted
        ListNode* toDelete = slow->next;
        cout<<slow->val;
        slow->next = slow->next->next;
        delete toDelete;

        // Get the real head and clean up dummy
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};