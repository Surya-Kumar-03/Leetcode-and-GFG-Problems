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
    // O(max(N, M)) O(max(N, M))
    // ListNode* ourAdder(ListNode* l1, ListNode* l2, int& carry){
    //     if(!l1 && !l2 && carry == 0) {
    //         return NULL;
    //     }
    //     int sum = carry;
    //     if(l1) sum += l1->val;
    //     if(l2) sum += l2->val;
    //     carry = sum / 10; //carry will be 1 if greater than 9
    //     ListNode* newNode = new ListNode(sum % 10);
    //     newNode->next = ourAdder(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry);
    //     return newNode;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int carry = 0;
        // return ourAdder(l1, l2, carry); RECURSIVE
        // ITERATIVE
        int sum = l1->val + l2->val;
        int carry = sum/10; 
        ListNode* head = new ListNode(sum%10);
        ListNode* node = head;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2 || carry){
            sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            } 
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            } 
            carry = sum/10;
            ListNode* newNode = new ListNode(sum % 10);
            node->next = newNode;
            node = node->next;
        }   
        return head;
    }
};