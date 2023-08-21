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
    ListNode* getKth(ListNode* traverser, int k) {
        ListNode* kth = NULL;
        for(int i = 0; i < k; i++) {
            if(traverser == NULL) break;
            if(i == k - 1) kth = traverser;
            traverser = traverser->next;
        }
        return kth;
    }

    ListNode* reverseKNodes(ListNode* traverser, int k, ListNode* kthNext) {
        ListNode* prev = kthNext;
        while(traverser != NULL && k > 0) {
            ListNode* next = traverser->next;
            traverser->next = prev;
            prev = traverser;
            traverser = next;
            k--;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == nullptr) return head;

        ListNode* traverser = head;
        ListNode* dummy = new ListNode(0); 
        ListNode* ans = dummy;

        while(traverser != NULL) {
            ListNode* kth = getKth(traverser, k);
            if(kth) {
                ListNode* kthNext = kth -> next;
                ListNode* newHead = reverseKNodes(traverser, k, kthNext);
                dummy -> next = newHead;
                dummy = traverser;
                traverser = kthNext;
            } else {
                break;
            }
        }
        
        return ans->next;
    }
};