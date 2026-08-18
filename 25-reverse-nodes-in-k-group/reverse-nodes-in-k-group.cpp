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
    ListNode* reverseList(ListNode* head , int k) {
        if(head == NULL || k==1) return head;

        ListNode* newHead = reverseList(head->next, k-1);
        head->next->next = head;
        head->next=NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k==1) return head;

        // check if there exist required no. of nodes
        ListNode* temp = head;
        for(int i = 0;i<k;i++){
            if(temp == NULL ) return head;
            temp = temp ->next;
        }

        ListNode* nextGroup = temp;

        ListNode* newHead = reverseList(head,k);
        
        // head is now at tail of first group
        head ->next = reverseKGroup(nextGroup, k);

        return newHead;
    }
};