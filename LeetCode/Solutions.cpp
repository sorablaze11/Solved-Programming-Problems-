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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* addedNumber = new ListNode(0);
        ListNode* prev = addedNumber;
        int carry = 0, rem = 0;
        while(l1 != NULL && l2 != NULL) {
            rem = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            prev->next = temp;
            prev = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            rem = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            prev->next = temp;
            prev = temp;
            l1 = l1->next;
        }
        while(l2 != NULL){
            rem = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            prev->next = temp;
            prev = temp;
            l2 = l2->next;
        }
        if(carry){
            ListNode *temp = new ListNode(carry);
            prev->next = temp;
        }
        return addedNumber->next;
    }
};