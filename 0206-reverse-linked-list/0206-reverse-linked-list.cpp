class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next; // store
            curr->next = prev;          // reverse link
            prev = curr;                // move prev
            curr = next;                // move curr
        }

        return prev;
    }
};
