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
    int getSize(ListNode* head) {
        if(head == NULL) return 0;
        int size = 0;
        while(head != NULL) {
            head = head -> next;
            size++;
        }
        return size;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = getSize(head);
        int partSize = size / k;
        int extra = 0;
        if((partSize * k) != size) {
            extra = size - (partSize * k);
        }

        ListNode* dummy = head;
        vector<ListNode*> ans;
        bool initial = true;
        for(int i = 0; i < k; i++) {
            ans.push_back(dummy);
            for(int i = 0; i < partSize - 1; i++) {
                dummy = dummy -> next;
            }
            if(extra > 0 && partSize != 0) {
                dummy = dummy -> next;
                extra--;
            }
            initial = false;
            if(dummy != NULL) {
                ListNode* temp = dummy -> next;
                dummy -> next = NULL;
                dummy = temp;
            }
        }
        return ans;
    }
};