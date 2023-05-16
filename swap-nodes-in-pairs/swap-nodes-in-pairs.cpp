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
    ListNode* ourSwapper(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        // 3 medha recursion
        ListNode* ans =  ourSwapper(head->next->next);
        ListNode* temp = head->next; // 2 node
        head->next =  ans; // 1 ki next emo 3 medha recursion
        temp->next = head;
        return temp;
    }

    ListNode* swapPairs(ListNode* head) {
        return ourSwapper(head);
    }
};