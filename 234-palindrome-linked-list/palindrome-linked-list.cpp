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
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if (!head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow at left middle or middle
        ListNode* newhead = reverseLL(slow->next);
        ListNode* a = head;
        ListNode* b = newhead;
        while (a && b) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};