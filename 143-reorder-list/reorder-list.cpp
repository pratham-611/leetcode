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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head ->next == NULL ) return head;

        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next=NULL;
        return temp;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        ListNode* newHead = reverseList(head2);


        ListNode* newlist = new ListNode(-1);
        ListNode* a = head;
        ListNode* b = newHead;
        ListNode* c = newlist;

        bool flag = true;
        while(a && b){
            if(flag ){
                c->next = a;
                a = a->next;
                flag= !flag;
            }
            else {
                c->next = b;
                b = b->next;
                flag= !flag;
            }
            c = c->next;
        }
        c->next = a? a :b;
    }
};