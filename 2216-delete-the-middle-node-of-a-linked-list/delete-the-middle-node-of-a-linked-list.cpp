class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Case 1: 0 or 1 node
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        // Find middle node
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Delete middle node
        prev->next = slow->next;

        return head;
    }
};
