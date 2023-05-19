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
    ListNode*  reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head != NULL) {
            ListNode* temp = head -> next;
            head -> next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

    // Recursive Practise
    // ListNode* reverseList(ListNode* head){
    //     if(!head || !head->next) return head;
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head; //the last node in the reversed guy to point to our node
    //     head->next = NULL;  // our node next  is null now
    //     return newHead;
    // }


    // Recursive
    // ListNode* reverseList(ListNode* head) {
    // if(head == NULL || head->next == NULL)
    //     return head;
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return newHead;
    // }
    
    // Iterative
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* newHead = NULL;
    //     while(head != NULL)
    //     {
    //         ListNode* next = head->next;
    //         head->next = newHead;
    //         newHead = head;
    //         head = next;
    //     }
    //     return newHead;
    // }

    // my practise
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode* prevNext = head -> next;
    //     ListNode* lastNode = head;
    //     lastNode -> next = NULL;
    //     while(prevNext != NULL) {
    //         ListNode* temp = prevNext -> next;
    //         prevNext -> next = lastNode;
    //         lastNode = prevNext;
    //         prevNext = temp;
    //     }
    //     return lastNode;
    // }
};