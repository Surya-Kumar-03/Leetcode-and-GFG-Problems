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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        bool isFirst = true;
        ListNode* curHead = new ListNode(0);
        ListNode* curTail = curHead;
        while (head != NULL) {
            if (head->val == 0) {
                if (isFirst) {
                    sum = 0;
                    isFirst = false;
                } else {
                    curTail->next = new ListNode(sum);
                    curTail = curTail->next;
                    sum = 0;
                }
            } else {
                sum += head->val;
            }
            head = head->next;
        }
        return curHead->next;
    }
};