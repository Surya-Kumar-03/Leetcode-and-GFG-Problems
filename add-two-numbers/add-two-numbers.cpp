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
    ListNode* ourAdder(ListNode* l1, ListNode* l2, int& carry){
        if(!l1 && !l2 && carry != 0) {
            return new ListNode(carry);
        } else if(!l1 && !l2) {
            return NULL;
        } else if(!l1 && carry == 0) {
            return l2;
        } else if(!l2 && carry == 0) {
            return l1;
        } else {
            int sum = 0;
            if(l1){
                sum += l1->val;
            }
            if(l2){
                sum += l2->val;
            }
            sum += carry;
            carry = sum / 10; //carry will be 1 if greater than 9
            ListNode* newNode = new ListNode(sum % 10);
            if(l1 && l2) {
                newNode->next = ourAdder(l1-> next, l2-> next, carry);
            } else if(l1){
                newNode->next = ourAdder(l1-> next, NULL, carry);
            } else {
                newNode->next = ourAdder(NULL, l2-> next, carry);
            }
            return newNode;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        return ourAdder(l1, l2, carry);
    }
};