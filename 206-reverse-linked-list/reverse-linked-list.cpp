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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // initialize prev
        ListNode* cur = head;
        ListNode* next = nullptr;

        while (cur != nullptr) {
            next = cur->next;   // store next node
            cur->next = prev;   // reverse pointer
            prev = cur;         // move prev forward
            cur = next;         // move cur forward
        }
        return prev;  // prev will be new head
    }
};
