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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* c = new ListNode(-1);
        ListNode* temp = c;
        while(l1 || l2){
            int a = l1?l1->val:0;
            int b = l2?l2->val:0;

            sum = carry + a + b;
            carry = sum/10;
            sum = sum % 10;
            temp -> next  = new ListNode(sum);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            temp = temp->next;
        }
        if( carry  == 1 ) {
            temp->next = new ListNode(1);
        }
        return c->next;
    }
};