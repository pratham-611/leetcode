class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy, *cur = head;

        while (cur) {
            bool dup = false;

            while (cur->next && cur->val == cur->next->val) {
                dup = true;
                cur = cur->next;
            }

            if (dup)
                prev->next = cur->next;
            else
                prev = cur;

            cur = cur->next;
        }

        return dummy->next;
    }
};