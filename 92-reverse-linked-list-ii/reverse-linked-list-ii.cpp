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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        if(!head||left==right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* cur = prev->next;
        ListNode* prevR = nullptr;

        
        for(int i=0;i<(right-left+1);i++){
            ListNode* next = cur->next;
            cur->next = prevR;
            prevR = cur;
            cur = next; 
        }
        prev->next->next = cur;
        prev->next = prevR;

        return dummy->next;
    }
};