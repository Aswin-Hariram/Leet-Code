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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // find length & tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // effective rotation
        k %= length;
        if (k == 0) return head;

        // make circular
        tail->next = head;

        // find new tail (length - k - 1 steps)
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // set new head and break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
