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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        if(head->next == NULL) return NULL;
        while(n){
            fast= fast-> next;
            n--;
        }
        if(fast == NULL) head=head->next;
        while(fast != NULL){
            prev=slow;
            slow= slow->next;
            fast= fast->next;
        }
        prev->next = slow->next;
        return head;
    }
};