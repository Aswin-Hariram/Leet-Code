/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Step 1: find length
        int length = 0;
        ListNode* cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        // Step 2: find k-th node from start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 3: find k-th node from end -> (length - k + 1)
        ListNode* second = head;
        for (int i = 1; i <= length - k; i++) {
            second = second->next;
        }

        // Step 4: swap values
        swap(first->val, second->val);

        return head;
    }
};
