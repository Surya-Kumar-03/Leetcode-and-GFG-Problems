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
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* topGuy = head;
        for(int i = 0; i < k; i++) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        topGuy -> next = head;
        return prev;
    }   

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        dummy -> next = head;
        for(int i = 0; i < left - 1; i++) {
            dummy = dummy -> next;
        }

        if(left != right) {
            dummy -> next = reverseKNodes(dummy -> next, right - left + 1);
        }
        return temp -> next;
    }
};