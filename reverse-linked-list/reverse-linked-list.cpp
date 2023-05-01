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
        if(head == NULL || head->next == NULL) return head;
        ListNode* prevNext = head -> next;
        ListNode* lastNode = head;
        lastNode -> next = NULL;
        while(prevNext != NULL) {
            ListNode* temp = prevNext -> next;
            prevNext -> next = lastNode;
            lastNode = prevNext;
            prevNext = temp;
        }
        return lastNode;
    }
};