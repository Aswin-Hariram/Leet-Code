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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);  // helps handle head duplicates
        ListNode* prev = dummy;                   // last confirmed unique node
        ListNode* cur = head;

        while (cur) {
            // check if this node starts a duplicate sequence
            bool duplicate = false;
            while (cur->next && cur->val == cur->next->val) {
                duplicate = true;
                cur = cur->next;  // skip all duplicates
            }

            if (duplicate) {
                // skip the entire duplicate block
                prev->next = cur->next;
            } else {
                // no duplicate → move prev forward
                prev = prev->next;
            }

            cur = cur->next; // always move fast pointer
        }

        return dummy->next;
    }
};
