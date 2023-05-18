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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = NULL;
        for(int i = 0; i < n; i++) {
            fast =  fast -> next;
        }

        if(fast == NULL) return head->next;
        while(fast != NULL) {
            if(slow == NULL){
                slow = head;
                fast = fast -> next;
            } else {
                slow = slow -> next;
                fast = fast -> next;
            }
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};