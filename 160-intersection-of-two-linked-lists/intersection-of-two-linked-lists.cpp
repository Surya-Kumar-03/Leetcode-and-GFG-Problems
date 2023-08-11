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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //traverse for length of first head
        if(!headA && !headB) return NULL;
        if(!headA || !headB) return NULL;
        int len1 = 0, len2 = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(headA -> next != NULL) {
            headA = headA -> next;
            len1++;
        }

        while(headB -> next != NULL) {
            headB = headB -> next;
            len2++;
        }

        if(headA == headB) {
            if(len1 > len2) {
                while(len1 > len2) {
                    tempA = tempA -> next;
                    len1--;
                }
            } else if(len2 > len1) {
                while(len2 > len1) {
                    tempB = tempB -> next;
                    len2--;
                }
            }
            while(tempA != tempB) {
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
            return tempA; //or tempB can be returned
        } else return NULL;
    }
};