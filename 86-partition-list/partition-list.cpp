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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0); 
        ListNode* lessPtr = dummyLess; 
        ListNode* dummyGreater = new ListNode(0); 
        ListNode* greaterPtr = dummyGreater; 
        
        while (head != NULL) {
            if (head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            head = head->next;
        }
        
        greaterPtr->next = NULL;
        lessPtr->next = dummyGreater->next; 
        
        return dummyLess->next; 
    }
};