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
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    int pairSum(ListNode* head) {
        if(head == NULL) return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pairHead = reverseList(slow->next);
        int maxVal = 0;
        while(head != slow->next) {
            maxVal = max(maxVal, head->val + pairHead->val);
            head = head->next;
            pairHead = pairHead->next;
        }
        return maxVal;
    }
};