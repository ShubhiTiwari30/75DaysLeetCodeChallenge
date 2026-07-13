class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. dummy / temp node
        ListNode* temp = new ListNode(0);
        temp->next = head;

        // 2. fast & slow
        ListNode* fast = temp;
        ListNode* slow = temp;

        // 3. fast ko n step aage
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 4. dono saath chalao
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // 5. delete node
        slow->next = slow->next->next;

        // 6. new head return
        return temp->next;
    }
};
