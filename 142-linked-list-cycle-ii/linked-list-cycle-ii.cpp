/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        while(fast != NULL && fast->next != NULL) { 
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle) return NULL;
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};