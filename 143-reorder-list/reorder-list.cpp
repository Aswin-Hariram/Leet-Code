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
    void reorderList(ListNode* head) {
        

        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;

        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur=next;
        }

        slow->next = nullptr;

        ListNode* first = head;
        ListNode* second = prev;
        
        while(second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

        //return head;

    }
};