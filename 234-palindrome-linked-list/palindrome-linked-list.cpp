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
    ListNode* reverse(ListNode* slow) {
        ListNode* next = NULL;
        while(slow != NULL) {
            ListNode* temp = slow -> next;
            slow -> next = next;
            next = slow;
            slow = temp;
        }
        return next;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* mid = reverse(slow);
        while(head != NULL && mid != NULL) {
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};