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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next; // skip the first 0
        ListNode* curr = temp; 
        int val = 0;

        while (curr) {
            if (curr->val == 0) {
                // assign sum to temp and move forward
                temp->val = val;
                temp->next = curr->next;
                temp = temp->next;
                val = 0; // reset
            } else {
                val += curr->val;
            }
            curr = curr->next;
        }

        return head->next; // skip the first dummy 0
    }
};
