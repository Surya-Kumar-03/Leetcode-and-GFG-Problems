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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2) {
            if(!list1) return list2;
            else return list1;
        }
        ListNode* head = NULL;
        ListNode* ans = NULL;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                if(head == NULL){
                    head = list1;
                    ans = head;
                } 
                else {
                    head -> next = list1;
                    head = head->next;
                }
                list1 = list1->next;
            } else  {
                if(head == NULL) {
                    head = list2;
                    ans = head;
                }
                else {
                    head -> next = list2;
                    head = head->next;
                }
                list2 = list2->next;
            }
        }
        while(list1 != NULL) {
            head->next = list1;
            head = head->next;
            list1 = list1 -> next;
        }
        while(list2 != NULL) {
            head->next = list2;
            head = head->next;
            list2 = list2 -> next;
        }
        return ans;
    }
};