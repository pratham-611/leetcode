/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa = headA;
        ListNode* tempb = headB;
        int n1=0 , n2 = 0;

        while(tempa){
            n1++;
            tempa = tempa -> next;
        }
        while(tempb){
            n2++;
            tempb = tempb -> next;
        }

        int diff = abs(n1-n2);
        tempa = headA;
        tempb = headB;

        while(diff--){
            if(n1>n2) tempa = tempa -> next;

            if(n2>n1) tempb = tempb -> next;
        }
        while(tempa != tempb){
            tempa = tempa ->next;
            tempb = tempb ->next;
        }
        return tempa;
    }
};