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
            int firstVal = 0, secondVal = 0;
            if(l1){
                firstVal = l1->val;
            }
            if(l2){
                secondVal = l2->val;
            }
            int val = firstVal + secondVal + carry;
            if(val > 9) {
                carry = 1;
                val = val % 10;
            } else carry = 0;
            ListNode* newNode = new ListNode(val);
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